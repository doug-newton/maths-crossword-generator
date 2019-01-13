#include "worksheet.h"
#include "crosswordworksheet.h"
#include <fstream>
#include "alphabettable.h"
#include "menu.h"
#include "filereader.h"
#include <limits>

std::vector<std::string> bodmasVariants;
std::vector<std::string> worksheetCommands;

//	name with no extensions
std::string worksheetName;

//	data/worksheets/<worksheetName>/
std::string worksheetFolder;

//	path to the list of commands to build the worksheet
//	data/worksheets/<worksheetName>/<worksheetName>.commands
std::string worksheetPath;

//	'local' names without folder
std::string questionsFileName;
std::string memoFileName;

//	path to the tex memo file
//	data/worksheets/<worksheetName>/<worksheetName>-memo.tex
std::string memoPath;

//	data/worksheets/<worksheetName>/<worksheetName>.tex
std::string questionsPath;

std::vector<std::string> worksheetNames;

void makeWorksheetNames(const std::string name);
void clearCin();
void parseCommand(const std::string& command, std::vector<std::string>& args);
void readVariantsFile();
void writeWorksheet();
int inputMenuNumber();
int inputNumber();
int selectFromVariants(std::vector<std::string>& vars);
int indexFromMenuOptions(std::vector<std::string>& menuOptions);
int main();
int doMenu();
void readWorksheetFile(std::string worksheetName);
void makeWorksheet();
void makeWorksheetNames(const std::string name);
void writeWorksheetCommands();

//	read the names of all the worksheets from data/worksheetnames.txt
void readWorksheetNames();
std::map<std::string,bool> mHasWorksheetName;

void saveWorksheetNames();
bool usedWorksheetName(std::string name);

int inputMenuOption(std::vector<std::string> menuOptions);

std::string chooseQuestionAndVariant();

int qweqwe123() {

	int seed;
	bool ok = false;

	while (not ok) {
		srand(time(0));
		seed = rand()%1000;
		CrosswordWorksheet worksheet;
		worksheet.setSeed(seed);
		worksheet.setDisplayAnswers(true);
		worksheet.buildCrosswordOnly();

		std::ofstream filestream("preview.tex");
		worksheet.outputQuestions(filestream);
		filestream.close();

		system("pdflatex preview.tex");
		system("evince preview.pdf");

		int i = inputMenuOption({
				"OK",
				"Next seed"
			}
		);

		switch (i) {
			case '1': ok = true; break;
			default: break;
		}

	}

}

int main() {
	CrosswordWorksheet worksheet;
	worksheet.setSeed(867);
	worksheet.setDisplayAnswers(true);
	worksheet.makeCrossword();

	std::ofstream filestream("crossword.tex"), filestream2("crossword-memo.tex");

	worksheet.outputQuestions(filestream);
	worksheet.outputAnswers(filestream2);

	filestream.close();
	filestream2.close();

	system("pdflatex crossword.tex");
	system("evince crossword.pdf");

	return 0;
}

int inputMenuOption(std::vector<std::string> menuOptions) {
	int i = 1;
	for (std::string& str: menuOptions) {
		std::cout << "1. " << str << std::endl;
		i++;
	}

	return inputMenuNumber();
}

void readWorksheetNames() {
	FileReader reader;
	worksheetNames = std::vector<std::string>();
	mHasWorksheetName = std::map<std::string, bool>();
	reader.readFileIntoVector("data/worksheetnames.txt",worksheetNames);
}

void writeWorksheetCommands() {
	std::string cmd = "mkdir " + worksheetFolder;
	system(cmd.c_str());

	std::ofstream filestream(worksheetPath);
	for (std::string& command: worksheetCommands) {
		filestream << command << std::endl;
	}
	filestream.close();
}

void makeWorksheetNames(const std::string name) {
	worksheetName = name;
	worksheetFolder = "data/worksheets/"+worksheetName+"/";

	questionsFileName = worksheetName + ".tex";
	memoFileName = worksheetName + "-memo.tex";

	worksheetPath = worksheetFolder + worksheetName + ".commands";
	memoPath = worksheetFolder + memoFileName;
	questionsPath = worksheetFolder + questionsFileName;
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int inputMenuNumber() {
	std::cout << "Enter number: ";
	std::string result;
	getline(std::cin, result);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	return std::stoi(result);
}

int inputNumber() {
	std::cout << "Enter number: ";
	std::string result;
	getline(std::cin, result);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	return std::stoi(result)-1;
}

void parseCommand(const std::string& command, std::vector<std::string>& args) {
	std::size_t pos = 0;
	std::size_t spacePos = 0;

	while (pos < command.length()) {
		spacePos = command.find(" ", pos);
		if (spacePos == std::string::npos) {
			spacePos = command.length();
		}
		std::string arg = command.substr(pos, spacePos - pos);
		args.push_back(arg);
		pos = spacePos + 1;
	}
}

int selectFromVariants(std::vector<std::string>& vars) {
	std::cout << "Choose a variant..." << std::endl;
	clearCin();

	Worksheet worksheet;

	worksheet.command({"SECTION","Select a variant"});
	worksheet.command({"ENUMERATE"});

	for (std::string& variant: vars) {
		std::vector<std::string> args;
		parseCommand(variant, args);
		worksheet.command(args);
	}

	worksheet.command({"ENDENUMERATE"});
	worksheet.command({"ENDSECTION"});

	std::ofstream filestream("data/preview.tex");
	worksheet.outputQuestions(filestream);
	filestream.close();
	system("cd data; pdflatex preview.tex; evince preview.pdf");

	return inputNumber();
}

void readVariantsFile() {
	FileReader fileReader;
	std::vector<std::string> variants;
	fileReader.readFileIntoVector("data/variants.txt", variants);

	for (std::string& variant: variants) {
		std::vector<std::string> args;
		parseCommand(variant, args);
		if (args[0] == "BODMAS") {
			bodmasVariants.push_back(variant);
		}
	}
}

int indexFromMenuOptions(std::vector<std::string>& menuOptions) {
	for (int i=0; i<menuOptions.size(); i++) {
		std::cout << (i+1) << ") " << menuOptions[i] << std::endl;
	}

	return inputNumber();
}

//	deprecated, use makeWorksheet
void writeWorksheet() {
	Worksheet worksheet;

	worksheet.command({"SECTION","Select a variant"});
	worksheet.command({"ENUMERATE"});

	for (std::string& variant: worksheetCommands) {
		std::vector<std::string> args;
		parseCommand(variant, args);
		worksheet.command(args);
	}

	worksheet.command({"ENDENUMERATE"});
	worksheet.command({"ENDSECTION"});

	std::cout << "Please enter a name for the worksheet: ";
	std::string worksheetName;

	getline(std::cin, worksheetName);
	clearCin();

	std::string folderName = "data/worksheets/" + worksheetName;
	std::string localFileName = worksheetName + ".tex";
	std::string localFileMemoName = worksheetName + "-memo.tex";
	std::string texFileName = folderName + "/" + worksheetName + ".tex";
	std::string texFileMemoName = folderName + "/" + worksheetName + "-memo.tex";

	std::string mkdirCommand = "mkdir " + folderName;

	system(mkdirCommand.c_str());

	std::ofstream filestream(texFileName);
	worksheet.outputQuestions(filestream);
	filestream.close();

	std::ofstream filestreamMemo(texFileMemoName);
	worksheet.outputAnswers(filestreamMemo);
	filestreamMemo.close();

	std::string compileAndOpenCommand = "cd " + folderName + "; pdflatex "
		+ localFileName + "; evince " + worksheetName + ".pdf";
	std::string compileMemoCommand = "cd " + folderName + "; pdflatex "
		+ localFileMemoName;

	system(compileMemoCommand.c_str());
	system(compileAndOpenCommand.c_str());
}

void readWorksheetFile(std::string worksheetName) {
	FileReader fileReader;

	makeWorksheetNames(worksheetName);
	worksheetCommands = std::vector<std::string>();

	fileReader.readFileIntoVector(worksheetPath, worksheetCommands);
}

void makeWorksheet() {
	//	make a worksheet and execute all commands

	Worksheet worksheet;

	for (std::string& command: worksheetCommands) {
		std::vector<std::string> args;
		parseCommand(command, args);
		worksheet.command(args);
	}

	//	create tex files based on the worksheet's name

	//	create the folder
	std::string cmd = "mkdir " + worksheetFolder;
	system(cmd.c_str());

	//	create the tex files (memo and question)
	std::ofstream questionsFile(questionsPath), memoFile(memoPath);
	worksheet.outputQuestions(questionsFile);
			/*	worksheet.outputAnswers(memoFile);*/
	questionsFile.close();
	memoFile.close();

	//	compile them
	cmd = "cd " + worksheetFolder + "; " + 
		"pdflatex " + questionsFileName + "; " + 
		"pdflatex " + questionsFileName + "";
	system(cmd.c_str());

	cmd = "evince " + worksheetFolder + worksheetName + ".pdf";
	system(cmd.c_str());

}


int doMenu() {
	readWorksheetNames();
	readVariantsFile();

	int choice = 0;
	int exitI = 123;
	while (choice != exitI) {
		std::vector<std::string> menuOptions = {
			"Add Questions",		//	1
			"Save Worksheet",		//	2
			"Load Worksheet",		//	3
			"Compile Worksheet",	//	4
			"Quit (123)"
		};

		for (int i=0; i<menuOptions.size(); i++) {
			std::cout << (i+1) << ") " << menuOptions[i] << std::endl;
		}

		choice = inputMenuNumber();

		switch(choice) {
			case 1:
				{
					/*
					std::vector<std::string> menuOptions = {
						"Order of Operations",
					};

					for (int i=0; i<menuOptions.size(); i++) {
						std::cout << (i+1) << ") " << menuOptions[i] << std::endl;
					}

					choice = inputMenuNumber();
					*/
					int choice = inputMenuOption({
						"Order of Operations",
					});

					switch (choice) {
						case 1:
							{
								int index = selectFromVariants(bodmasVariants);
								std::string& variant = bodmasVariants[index];
								std::cout << "How many?" << std::endl;
								int number = inputMenuNumber();

								worksheetCommands.push_back("ENUMERATION");

								for (int q=0; q<number; q++ ) {
									worksheetCommands.push_back(variant);
								}
								
								worksheetCommands.push_back("ENDENUMERATION");

								std::cout << number << " x " << variant
									<< " added successfully" << std::endl;
							}
							break;
						default: break;
					}
				}
				break;
			case 2:
				{
					if (worksheetName == "") {
						std::string name;
						std::cout << "Enter a name for the worksheet: ";
						getline(std::cin, name);
						clearCin();
						makeWorksheetNames(name);
					}
				}
				writeWorksheetCommands();
				break;
			case 3:
				{
					readWorksheetNames();
					int index = inputMenuOption(worksheetNames);
					readWorksheetFile(worksheetNames[index]);
				}
				break;
			case 4:
				{
					if (worksheetName == "") {
						std::string name;
						std::cout << "Enter a name for the worksheet: ";
						getline(std::cin, name);
						clearCin();
						makeWorksheetNames(name);
					}
					makeWorksheet();
				}
				break;

			default:
				break;
		}

		if (choice==exitI) break;
	}

	return 0;
}

std::string chooseQuestionAndVariant() {
	int choice = inputMenuOption({
		"Order of Operations",
	});

	switch (choice) {
		case 1:
			{
				int index = selectFromVariants(bodmasVariants);
				std::string& variant = bodmasVariants[index];
				return variant;
			}
			break;
		default: break;
	}
}
