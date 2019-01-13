#include "crossword.h"

Vec2::Vec2()
	:x(0),y(0)
{
}

Vec2::Vec2(int x,int y)
	:x(x),y(y)
{
}

bool Vec2::operator<(const Vec2& other) const {
	if (other.x < x) {
		return true;
	} else if (other.x == x) {
		if ( other.y < y ) return true;
		else return false;
	} else if (other.x > x) {
		return false;
	}
}

WordPosition::WordPosition()
	:x(0),y(0),across(true)
{
}

WordPosition::WordPosition(int x,int y,bool across)
	:x(x),y(y),across(across)
{
}

bool Crossword::getDisplayAnswers() {
	return displayAnswers;
}

void Crossword::setDisplayAnswers(bool b) {
	this->displayAnswers = b;
}

/*	Tries to add a word by connecting it to another (unless it is the first word).
 *	Returns true if the word was inserted successfully.
 *	The word will not be inserted if it is already in the crossword.
 */
bool Crossword::addWord(std::string word) {
	//	prevent adding if the word is already in the crossword
	if (wordPositions.find(word) != wordPositions.end()) {
		return false;
	}

	for (auto& existingWord: words) {
		for (int i=0; i < existingWord.length(); i ++) {
			for (int j=0; j < word.length(); j ++) {
				if (existingWord[i] == word[j]) {
					//	if the word was connected there successfully
					if (addConnectedTo(word,j,existingWord,i))
						return true;
				}
			}
		}
	}

	if ( words.size() == 0) {
		//	it's the first word
		addWord(word,0,0,true);
		return true;
	}

	//	could not connect the word
	std::cout << "failed to connect " << word << " to any in the crossword" << std::endl;
	return false;
}

/*	Checks if the word collides with any others if it is placed
 *	at (x,y), but ignores collisions with the sourceWord (the one it is
 *	attached to).
 *	Orientation is taken to be the inverse of the sourceWord.
 *	Returns true if there is a collision.
 */
bool Crossword::collisionCheck(std::string word,int x,int y,std::string sourceWord) {
	WordPosition position = wordPositions[sourceWord];

	int abx,aby,aex,aey;
	//	orientation of word
	bool across = !position.across;

	/*	Make a bounding box padded by one unit. This is because two words can't
	 *	be right next to each other.
	 */
	if (across) {
		abx = x - 1;
		aex = x + word.length();
		aby = y - 1;
		aey = y + 1;
	} else {
		abx = x - 1;
		aex = x + 1;
		aby = y - 1;
		aey = y + word.length();
	}

	//	check collision with each word (bounding boxes aren't padded; one is enough)

	for (auto& kv: wordPositions) {
		if (kv.first == sourceWord) continue;

		WordPosition bPosition = kv.second;

		int len = kv.first.length();
		int bbx, bex, bby, bey;

		bbx = bPosition.x;
		bby = bPosition.y;
		bex = bPosition.x;
		bey = bPosition.y;

		if (bPosition.across) bex = bPosition.x + len - 1;
		else bey = bPosition.y + len - 1;

		if (collides(abx,aex,aby,aey,bbx,bex,bby,bey)) return true;
	}

	return false;
}

/*	Standard AABB collision check.
 *	Returns true if there is a collision.
 */
bool Crossword::collides(int abx,int aex,int aby,int aey,
		int bbx,int bex,int bby,int bey) {

	if (aex < bbx) return false;
	if (bex < abx) return false;
	if (aey < bby) return false;
	if (bey < aby) return false;

	return true;
}

void Crossword::addWord(std::string word, int x, int y, bool across) {
	WordPosition wordPosition(x,y,across);
	wordPositions[word] = wordPosition;
	words.push_back(word);
	posToWordIndex[Vec2(x,y)] = words.size()-1;

	for (int i = 0; i < word.length(); i ++) {
		grid.setChar(x,y,word[i]);
		if (across) x++;
		else y++;
	}
}

/*	Tries to add the word connected to the source word at the specified word
 *	indices.
 *	Returns false if the word could not be added there, i.e. if there was a 
 *	collision with another word that prevented it.
 */
bool Crossword::addConnectedTo(std::string word, int wordI, std::string sourceWord,
		int sourceWordI) {
	if (wordPositions.find(sourceWord) == wordPositions.end()) {
		//	error
		return false;
	}

	WordPosition position = wordPositions[sourceWord];
	int x = position.x;
	int y = position.y;

	if (position.across) {
		x += sourceWordI;
		y -= wordI;
	}
	else {
		y += sourceWordI;
		x -= wordI;
	}

	if (collisionCheck(word,x,y,sourceWord)) {
		return false;
	}

	addWord(word,x,y,!position.across);

	return true;
}

std::string Crossword::getPositionAndOrientation(const std::string& word) {
	if (wordPositions.find(word)==wordPositions.end()) {
		std::cout << "could not find  " << word << " in crossword" << std::endl;
	}

	std::stringstream ss;

	WordPosition& position = wordPositions[word];
	int index = posToWordIndex[Vec2(position.x,position.y)] + 1;

	ss << index << " " << (position.across? " Across" : " Down") ;

	return ss.str();
}

std::string Crossword::strAscii() {
	return grid.strAscii();
}

void Crossword::latexPrint() {

}

/*	Returns the index (in 'words') of the word starting at the specified
 *	position or -1 if there is no word starting at that position.
 */
int Crossword::wordIndexAt(int x,int y) {
	x = grid.offsetX(x);
	y = grid.offsetY(y);
	if (posToWordIndex.find(Vec2(x,y))==posToWordIndex.end()) {
		return -1;
	}
	return posToWordIndex[Vec2(x,y)];
}

bool Crossword::hasIndexAt(int x, int y) {
	x = grid.offsetX(x);
	y = grid.offsetY(y);
	if (indexAtPos.find(Vec2(x,y))==indexAtPos.end()) {
		return false;
	}
	return true;
}

int Crossword::indexAt(int x, int y) {
	x = grid.offsetX(x);
	y = grid.offsetY(y);
	return indexAtPos[Vec2(x,y)];
}

CharGrid& Crossword::getGrid() {
	return grid;
}

void Crossword::makeNames() {
	std::vector<int> wordsAcrossY;
	std::map<int, std::string> yToWordAcross;

	std::vector<int> wordsDownX;
	std::map<int, std::string> xToWordDown;

	for (std::string& word: words) {
		WordPosition& position = wordPositions[word];
		if (position.across) {
			wordsAcrossY.push_back(position.y);
			yToWordAcross[position.y] = word;
		} else {
			wordsDownX.push_back(position.x);
			xToWordDown[position.x] = word;
		}
	}

	std::sort(wordsAcrossY.begin(), wordsAcrossY.end());
	std::sort(wordsDownX.begin(), wordsDownX.end());

	int index = 1;
	for (int y: wordsAcrossY) {
		std::string& word = yToWordAcross[y];
		WordPosition& position = wordPositions[word];
		std::stringstream ss;
		ss << index << " ACROSS";
		wordPositionNames[word] = ss.str();
		indexAtPos[Vec2(position.x, position.y)] = index;
		index ++;

		wordsInOrder.push_back(word);
	}

	index = 1;
	for (int x: wordsDownX) {
		std::string& word = xToWordDown[x];
		WordPosition& position = wordPositions[word];
		std::stringstream ss;
		ss << index << " DOWN";
		wordPositionNames[word] = ss.str();
		indexAtPos[Vec2(position.x, position.y)] = index;
		index ++;

		wordsInOrder.push_back(word);
	}
}

std::string Crossword::getNameOf(std::string word) {
	if (wordPositions.find(word) == wordPositions.end()) {
		return "HELLO";
	}
	else return wordPositionNames[word];
}

std::vector<std::string>& Crossword::getWordsInOrder() {
	return wordsInOrder;
}
