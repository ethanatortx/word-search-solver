
#define _USE_MATH_DEFINES
#include <cmath>
#include "wordSearch.h"

wordSearch::wordSearch(unsigned r, unsigned c)
{
	word_table = new charTable(r, c);
	fillTableWithRand(*word_table);
}

wordSearch::wordSearch(const char** warr, unsigned r, unsigned c)
{ word_table = new charTable(warr, r, c); }

wordSearch::wordSearch(charTable* ctbl)
{
	word_table = ctbl;
}

bool wordSearch::check(const std::string& word) const
{
	unsigned p, q, i, k;
	int x, y;
	for(p = 0; p < word_table->rows(); ++p)
	{
		for(q = 0; q < word_table->columns(); ++q)
		{
			if(word_table->at(p, q) == word[0])
			{
				for(k = 0; k < 8; ++k)
				{
					x = std::cos(k*(M_PI / 4));
					y = std::sin(k*(M_PI / 4));
					
					if(x < 0)
						x = std::floor(x);
					else if(x > 0)
						x = std::ceil(x);
					if(y < 0)
						y = std::floor(y);
					else if(y > 0)
						y = std::ceil(y);

					if(( (p + x) >= 0 && (p + x) < word_table->rows()) && 
						((q + y) >= 0 && (q + y) < word_table->columns()))
					{
						if(word_table->at(p + x, q + y) == word[1])
						{
							for(i = 1; i < word.size(); ++i)
							{
								x = std::cos(k*(M_PI / 4));
								y = std::sin(k*(M_PI / 4));
								
								if(x < 0)
									x = std::floor(x);
								else if(x > 0)
									x = std::ceil(x);
								if(y < 0)
									y = std::floor(y);
								else if(y > 0)
									y = std::ceil(y);
								
								if(( (p + x) >= 0 && (p + x) < word_table->rows()) && 
									((q + y) >= 0 && (q + y) < word_table->columns()))
								{
									
								}
							}
						}

					}
				}

				
			}
		}
	}
}

charTable& table() const
{ return (*word_table); }

wordSearch* constructWS(unsigned&& r, unsigned&& c, std::string* word, unsigned wCount)
{
	charTable* ctbl = new charTable(r, c);

}