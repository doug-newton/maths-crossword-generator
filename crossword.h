#ifndef CROSSWORD_H
#define CROSSWORD_H

#include "chargrid.h"
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

struct Vec2 {
	int x,y;
	Vec2();
	Vec2(int x,int y);
	bool operator<(const Vec2& other) const;
};

struct WordPosition {
	int x,y;
	bool across;
	WordPosition();
	WordPosition(int,int,bool);
};

class Crossword {

	public:
		/*	Attempts to add a word to the crossword by connecting it to another,
		 *	unless it is the first word.
		 *	Returns true if the word was added successfully.
		 */
		bool addWord(std::string word);
		void addWord(std::string word, int x, int y, bool across);

		/*	Tries to add the word connected to the source word at the specified word
		 *	indices.
		 *	Returns false if the word could not be added there, i.e. if there was a 
		 *	collision with another word that prevented it.
		 *	Will not add the word if it exists in the crossword.
		 */
		bool addConnectedTo(std::string word,int wordI,std::string sourceWord,
				int sourceWordI);

		/*	Checks if the word collides with any others if it is placed
		 *	at (x,y), but ignores collisions with the sourceWord (the one it is
		 *	attached to).
		 *	Orientation is taken to be the inverse of the sourceWord.
		 *	Returns true if there is a collision.
		 */
		bool collisionCheck(std::string word, int x,int y, std::string sourceWord);

		/*	Standard AABB collision check.
		 *	Returns true if there is a collision.
		 */
		bool collides(int abx,int aex,int aby,int aey,int bbx,int bex,int bby,int bey);

		std::string getPositionAndOrientation(const std::string& word);

		std::string strAscii();

		void latexPrint();

		int wordIndexAt(int x,int y);

		bool hasIndexAt(int x, int y);
		int indexAt(int x, int y);

		CharGrid& getGrid();

		/*	Gives a 'name' to each word, depending on its orientation and its
		 *	relation to other words in the crossword.
		 *	e.g. "1 ACROSS".
		 *	Must only be called once all words have been added into the crossword.
		 */
		void makeNames();

		/*	Gives the number and orientation of the word, e.g. "1 ACROSS".
		 */
		std::string getNameOf(std::string word);

		std::vector<std::string>& getWordsInOrder();

		bool getDisplayAnswers();
		void setDisplayAnswers(bool b);

	private:
		bool displayAnswers;
		std::map<std::string,WordPosition> wordPositions;
		std::map<std::string,std::string> wordPositionNames;
		std::vector<std::string> words;
		/*	Returns the index (in 'words') of the word starting at the specified
		 *	position or -1 if there is no word starting at that position.
		 */
		std::map<Vec2,int> posToWordIndex;
		CharGrid grid;

		std::map<Vec2,int> indexAtPos;

		std::vector<std::string> wordsInOrder;

		friend class LatexCrosswordPrinter;
};

#endif
