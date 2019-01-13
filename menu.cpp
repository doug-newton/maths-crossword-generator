#include "menu.h"
#include <iostream>
#include <limits>

void Menu::start() {
	makeChoiceLabels();
	loadVariants();

	std::vector<std::string> choices = {
		"Add Questions",
		"Preview"
	};

	std::string choice = chooseFrom(choices);


	if (choice == "Add Questions") {
		
		std::vector<std::string> choices = {
			"Order of Operations",
			"Exponents & Roots"
		};

		choice = chooseFrom(choices);

		if (choice == "Order of Operations" ) {
			displayVariantsPreview(bodmasVariants);
			choice = chooseFrom(bodmasVariants);
			std::vector<std::string> args;

			parseCommand(choice, args);
			for (std::string& a: args) {
				std::cout << a << std::endl;
			}
		}
	}

	else if (choice == "Preview") {
	}

}

char Menu::inputChar() {
	std::cout << "Enter your selection: ";
	std::string result;
	getline(std::cin, result);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	return result[0];
}

int Menu::inputNumber() {
	std::cout << "Enter number: ";
	std::string result;
	getline(std::cin, result);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	return std::stoi(result);
}

void Menu::parseCommand(const std::string& command, std::vector<std::string>& args) {
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

void Menu::loadVariants() {
	bodmasVariants.push_back("BODMAS DMAS 10 3");
}

void Menu::makeChoiceLabels() {
	choiceLabels = "qazwsxedcrfvtgbyhnujmikolp";
	for (int i=0; i<choiceLabels.length(); i++) {
		choiceLabelToIndex[choiceLabels[i]] = i;
	}
}

std::string& Menu::chooseFrom(std::vector<std::string>& choices) {
	for (int i=0; i<choices.size(); i++) {
		std::cout << labelOfIndex(i) << ". " <<  choices[i] << std::endl;
	}

	char c = inputChar();
	int i = choiceLabelToIndex[c];

	return choices[i];
}

char Menu::labelOfIndex(int index) {
	if (index > choiceLabels.length()) {
		//	error
		return 'E';
	}

	return choiceLabels[index];
}

void Menu::displayVariantsPreview(std::vector<std::string>& variants) {
	worksheet = Worksheet();

	for (std::string& variant: variants) {
		std::cout << "Q" << std::endl;
		std::vector<std::string> args;
		std::cout << "Q" << std::endl;
		parseCommand(variant, args);
		std::cout << "Q" << std::endl;
		worksheet.command(args);
	}

	std::ofstream stream("data/preview.tex");
	worksheet.outputQuestions(stream);
	stream.close();

	system("cd data; pdflatex preview.tex; evince preview.pdf");
}
