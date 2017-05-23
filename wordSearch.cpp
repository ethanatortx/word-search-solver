
#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>
#include <iostream>
#include "error.h"
#include "wordSearch.h"

wordSearch::wordSearch(unsigned r, unsigned c)
{
	word_table = new charTable(r, c);
	fillTableWithRand(*word_table);
}

wordSearch::wordSearch(const char* warr, unsigned r, unsigned c)
{ word_table = new charTable(warr, r, c); }

wordSearch::wordSearch(charTable* ctbl)
{
	word_table = ctbl;
}

bool wordSearch::search(const std::string& inpWord) const
{
	std::string word;
	std::cout << "Searching for " << inpWord << "...\n";
	for(auto& c : inpWord)
	{
		if( std::isalpha((int)c) ){
			if( std::isupper((int)c) )
				word.append(1, c);
			else if( std::islower((int)c) )
				word.append(1, std::toupper(c) );
		}
	}
	int p, q, i, k;
	
	double precx, precy;
	int x, y;

	int count = 0;
	for(p = 0; p < word_table->rows(); ++p)
	{
		for(q = 0; q < word_table->columns(); ++q)
		{
			std::cout << word[0] << ' ';
			if(word_table->at(p, q) == word[0])
			{
				std::cout << "Pass " << (++count) << "...\n";
				bool found;
				for(k = 0; k < 8; ++k)
				{
					for(i = 1; i < word.size(); ++i)
					{
						precx = std::cos(k*(M_PI / 4));
						precy = std::sin(k*(M_PI / 4));

						if(precx < -0.1)
							x = (int)std::floor(precx) * (i);
						else if(precx > 0.1)
							x = (int)std::ceil(precx) * (i);
						if(precy < -0.1)
							y = (int)std::floor(precy) * (i);
						else if(precy > 0.1)
							y = (int)std::ceil(precy) * (i);

						std::cout << "K: " << k << '\t';
						std::cout << "double x: " << precx << " double y: " << precy << '\t';
						std::cout << "real x: " << x << " real y: " << y << '\t';
						std::cout << "P: " << p << " Q: " << q << '\t';
						std::cout << "relative x: " << (p+x) << " relative y: " << (q+y) << '\n';

						if((((p + x) < 0) || ((p + x) >= word_table->rows())) || 
							(((q + y) < 0) || ((q + y) >= word_table->columns())))
						{
							found = 0;
							break;
						}
						else if(word_table->at((p + x), (q + y)) != word[i])
						{
							std::cout << "table char: " << word_table->at((p + x + 1), (q + y)) << " word char: " << word[i] << '\n';							
							found = 0;
							break;
						}
						else
						{
							std::cout << "table char: " << word_table->at((p + x), (q + y)) << " word char: " << word[i] << '\n';
							found = 1;
						}
					}
					if(found == 1)
						return true;
				}
			}
		}
	}
	return false;
}

charTable& wordSearch::table() const
{ return (*word_table); }

wordSearch* constructWS(unsigned&& r, unsigned&& c, std::string* word, unsigned wCount)
{
	charTable* ctbl = new charTable(r, c);

}