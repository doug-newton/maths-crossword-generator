#include "alphabettable.h"
#include <sstream>

AlphabetTable::AlphabetTable() 
{
	char c = 'A';
	
	for (int i=1; i<=26; i++) {
		std::stringstream a,n;
		a << c;
		n << i;
		append(n.str(), a.str());
		c++;
	}
}

