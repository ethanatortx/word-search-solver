
#include <iostream>
#include "charTable.h"
#include "wordSearch.h"
#include "process.h"

int main()
{
	int r, c, p, q;
	char a;
	#ifdef ONLY_ALPHA_CHAR
	std::cout << "only alpha characters will be accepted...\n";
	#endif
	std::cout << "rows? "; std::cin >> r;
	std::cout << "columns? "; std::cin >> c;
	charTable ctbl(r, c);
	fillTableWithRand(ctbl);
	ctbl.print();

	return 0;
}