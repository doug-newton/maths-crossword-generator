#ifndef SWAPPINGBUILDER_H
#define SWAPPINGBUILDER_H

#include "swapper.h"
#include "tree.h"
#include "random.h"
#include <vector>
#include <map>

#include "swapperplus.h"
#include "swapperminus.h"
#include "swappertimes.h"
#include "swapperdivide.h"

class SwappingBuilder {

	public:
		SwappingBuilder();
		void build(Tree* tree);
		void enableSwapper(std::string name);

	private:
		std::vector<Swapper*> swappers;
		std::map<std::string, Swapper*> swappersMap;

		SwapperPlus swapperPlus;
		SwapperMinus swapperMinus;
		SwapperTimes swapperTimes;
		SwapperDivide swapperDivide;

		Random random;

		void findLeaves(Node* node, std::vector<Node*>& leaves);
		Node* randomLeaf(Node* node, std::vector<Node*>& leaves);
};

#endif	//	SWAPPINGBUILDER_H
