#ifndef EQUATIONQUESTIONVARIANTCOEFF_H
#define EQUATIONQUESTIONVARIANTCOEFF_H

class EquationQuestionVariantCoeff: public EquationQuestionVariant {

	public:
		EquationQuestionVariantCoeff(
				std::vector<std::string>& args,
				EquationQuestion* question);
};

#endif
