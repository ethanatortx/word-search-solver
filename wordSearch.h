#ifndef _WORD_SEARCH_H_
#define _WORD_SEARCH_H_

#include <string>
#include "typeDef.h"
#include "charTable.h"

class wordSearch
{
public:
	wordSearch(unsigned, unsigned);
	wordSearch(const char*, unsigned, unsigned);
	wordSearch(charTable*);

	bool search(const std::string&) const;
	charTable& table() const;

private:
	charTable* word_table;
};

// generate word search with random filler
wordSearch* constructWS(unsigned&&, unsigned&&, std::string* words, unsigned wCount);

// This takes a seed for the prand number generator for creating characters
wordSearch* constructWS_seeded(unsigned&&, unsigned&&, std::string* words, unsigned wCount, unsigned seed);

#endif