#ifndef MENU_H
#define MENU_H

#include <map>
#include <string>
#include "worksheet.h"
#include <cstdlib>
#include <fstream>

class Menu {

	public:
		void start();

	protected:
		char inputChar();
		int inputNumber();

		void parseCommand(const std::string& command,std::vector<std::string>& args);

		/*	Obtaining the data.
		 */
		void loadVariants();

		/*	A mapping system of 'q'=1, 'a'=2, etc.
		 */
		std::string& chooseFrom(std::vector<std::string>& choices);
		char labelOfIndex(int index);
		void makeChoiceLabels();
		std::string choiceLabels;
		std::map<char, int> choiceLabelToIndex;

		/*	System to store and select question variants (commands)
		 */
		void displayVariantsPreview(std::vector<std::string>& variants);
		std::vector<std::string> bodmasVariants;

		Worksheet worksheet;
};

#endif
