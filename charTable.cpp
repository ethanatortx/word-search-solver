
#include <algorithm>
#include <iostream>
#include <cctype>
#include "typeDef.h"
#include "charTable.h"
#include "error.h"

charTable& fillTableWithRand(charTable& ctbl)
{
	int p, q;
	for(p = 0; p < ctbl.rows(); ++p)
		for(q = 0; q < ctbl.columns(); ++q)
			ctbl.set(randAlphaChar(), p, q);

	return ctbl;
}

charTable& fillTableWithSRand(charTable& ctbl, unsigned seed)
{
	std::srand(seed);
	return fillTableWithRand(ctbl);
}

bool operator==(const charTable& a, const charTable& b)
{
	if((a._rows != b._rows) || (a._columns != b._columns))
		return false;

	int p, q;
	for(p = 0; p < a._rows; ++p)
		for(q = 0; q < a._columns; ++q)
			if((a.at(p, q)) != (b.at(p, q)))
				return false;

	return true;
}

bool operator!=(const charTable& a, const charTable& b)
{
	if((a._rows != b._rows) || (a._columns != b._columns))
		return true;

	int p, q;
	for(p = 0; p < a._rows; ++p)
		for(q = 0; q < a._columns; ++q)
			if((a.at(p, q)) != (b.at(p, q)))
				return true;

	return false;
}

charTable::charTable(unsigned r, unsigned c):
	_rows(r), _columns(c)
{
	int p, q;
	arr = new char*[_rows];
	for(p = 0; p < _rows; ++p)
	{
		arr[p] = new char[_columns];
		for(q = 0; q < _columns; ++q)
			arr[p][q] = ' ';
	}
}

charTable::charTable(const char* str, unsigned r, unsigned c):
	_rows(r), _columns(c)
{
	arr = new char*[_rows];
	int p, q;
	for(p = 0; p < _rows; ++p)
		arr[p] = new char[_columns];

	#ifdef ONLY_ALPHA_CHAR
	for(p = 0; p < _rows; ++p)
		for(q = 0; q < _columns; ++q)
		{
			if(std::isalpha((int)(str[q + (p * _rows)])))
				arr[p][q] = str[q + (p * _rows)];
			else
				throw invalid_character();
		}
	#else
	for(p = 0; p < _rows; ++p)
		for(q = 0; q < _columns; ++q)
			arr[p][q] = str[q + (p * _rows)];
	#endif
}

charTable::charTable(const charTable& tbl):
	_rows(tbl._rows), _columns(tbl._columns)
{
	arr = new char*[_rows];
	int p, q;
	for(p = 0; p < _rows; ++p)
		arr[p] = new char[_columns];

	#ifdef ONLY_ALPHA_CHAR
	for(p = 0; p < _rows; ++p)
		for(q = 0; q < _columns; ++q)
		{
			if( ((int)(tbl.at(p, q)) >= 65 && (int)(tbl.at(p, q)) <= 90) ||
				((int)(tbl.at(p, q)) >= 97 && (int)(tbl.at(p, q)) <= 122) )
				arr[p][q] = tbl.at(p, q);
			else
				throw invalid_character();
		}
	#else
	for(p = 0; p < _rows; ++p)
		for(q = 0; q < _columns; ++q)
			arr[p][q] = tbl.at(p, q);
	#endif
}

charTable& charTable::operator=(const charTable& tbl)
{
	_rows = tbl._rows;
	_columns = tbl._columns;

	int p, q;
	for(p = 0; p < _rows; ++p)
		delete[] (arr[p]);

	delete[] arr;

	arr = new char*[_rows];
	for(p = 0; p < _rows; ++p)
	{
		arr[p] = new char[_columns];
		for(q = 0; q < _columns; ++q)
			arr[p][q] = tbl.at(p, q);
	}	

	return *this;
}

unsigned charTable::rows() const
{ return _rows; }
unsigned charTable::columns() const
{ return _columns; }
unsigned long charTable::size() const
{ return _rows * _columns; }

char charTable::at(unsigned r, unsigned c) const
{ return arr[r][c]; }
void charTable::set(const char a, unsigned r, unsigned c)
{
	#ifdef ONLY_ALPHA_CHAR
	if( ((int)a >= 65 && (int)a <= 90) ||
		((int)a >= 97 && (int)a <= 122) )
		arr[r][c] = a;
	else
		throw invalid_character();
	#else
	arr[r][c] = a;
	#endif
}

void charTable::setRow(const char* a, unsigned size, unsigned r, unsigned pos)
{
	int q, k = 0;
	#ifdef ONLY_ALPHA_CHAR
	for(q = pos; (q < _columns) && (q < size); ++q)
	{
		if( ((int)(a[k]) >= 65 && (int)(a[k]) <= 90) ||
			((int)(a[k]) >= 97 && (int)(a[k]) <= 122) )
			arr[r][q] = a[k++];
		else
			throw invalid_character();
	}
	#else
	for(q = pos; (q < _columns) && (q < size); ++q)
		arr[r][q] = a[k++];
	#endif
}

void charTable::setColumn(const char* a, unsigned size, unsigned c, unsigned pos)
{
	int p, k = 0;
	#ifdef ONLY_ALPHA_CHAR
	for(p = pos; (p < _rows) && (p < size); ++p)
	{
		if( ((int)(a[k]) >= 65 && (int)(a[k]) <= 90) ||
			((int)(a[k]) >= 97 && (int)(a[k]) <= 122) )
			arr[p][c] = a[k++];
		else
			throw invalid_character();
	}
	#else
	for(p = pos; (p < _rows) && (p < size); ++p)
		arr[p][c] = a[k++];
	#endif
}

void charTable::setTable(const char** a, unsigned sizeR, unsigned sizeC)
{
	int p, q;
	#ifdef ONLY_ALPHA_CHAR
	for(p = 0; (p < _rows) && (p < sizeR); ++p)
		for(q = 0; (q < _columns) && (q < sizeC); ++q)
		{
			if( ((int)(a[p][q]) >= 65 && (int)(a[p][q]) <= 90) ||
				((int)(a[p][q]) >= 97 && (int)(a[p][q]) <= 122) )
				arr[p][q] = a[p][q];
			else
				throw invalid_character();
		}
	#else
	for(p = 0; (p < _rows) && (q < sizeR); ++p)
		for(q = 0; (q < _columns) && (q < sizeC); ++q)
			arr[p][q] = a[p][q];
	#endif
}

void charTable::setTable(const char** a, unsigned sizeR, unsigned sizeC, unsigned offsetR, unsigned offsetC)
{
	int p, q, k = 0, j = 0;
	#ifdef ONLY_ALPHA_CHAR
	for(p = offsetR; (p < _rows) && (p < sizeR); ++p)
	{
		for(q = offsetC; (q < _columns) && (q < sizeC); ++q)
		{
			if( ((int)(a[k][j]) >= 65 && (int)(a[k][j]) <= 90) ||
				((int)(a[k][j]) >= 97 && (int)(a[k][j]) <= 122) )
				arr[p][q] = a[k][j++];
			else
				throw invalid_character();
		}
		j = 0;
		++k;
	}
	#else
	for(p = offsetR; (p < _rows) && (p < sizeR); ++p)
	{
		for(q = offsetC; (q < _columns) && (q < sizeC); ++q)
			arr[p][q] = a[k][j++];
		j = 0;
		++k;
	}
	#endif
}

void charTable::print() const
{
	int p, q;
	for(p = 0; p < _rows; ++p)
	{
		for(q = 0; q < _columns; ++q)
			std::cout << arr[p][q] << ' ';
		std::cout << std::endl;
	}
}

charTable::~charTable()
{
	int p;
	for(p = 0; p < _rows; ++p)
		delete[] (arr[p]);
	delete[] arr;
}
