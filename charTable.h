#ifndef _CHAR_TABLE_H_
#define _CHAR_TABLE_H_

#include <cstdlib>

class charTable
{
public:
	charTable(unsigned r, unsigned c);
	charTable(const char* str, unsigned r, unsigned c);
	charTable(const charTable& tbl);

	friend bool operator==(const charTable&, const charTable&);
	friend bool operator!=(const charTable&, const charTable&);
	charTable& operator=(const charTable& tbl);

	void clear();

	unsigned rows() const;
	unsigned columns() const;
	unsigned long size() const;

	char at(unsigned r, unsigned c) const;
	void set(const char a, unsigned r, unsigned c);
	void setRow(const char* a, unsigned size, unsigned r, unsigned pos = 0);
	void setColumn(const char* a, unsigned size, unsigned c, unsigned pos = 0);
	void setTable(const char** a, unsigned sizeR, unsigned sizeC);
	void setTable(const char** a, unsigned sizeR, unsigned sizeC, unsigned offsetX, unsigned offsetY);

	void print() const;

	~charTable();

private:
	unsigned _rows, _columns;
	mutable char** arr;
};

charTable& fillTableWithRand(charTable&);
charTable& fillTableWithSRand(charTable&, unsigned);

static inline char randAlphaChar() {
   long l;
   do { l = std::rand(); } while (l>=(RAND_MAX/26)*26);
   return (char)('A' + (unsigned)(l % 26));
}

#endif