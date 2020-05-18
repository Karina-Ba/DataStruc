#ifndef __PRINT_
#define __PRINT_

#include "Utils.h"
#include "BSTree.h"

class Print
{
	Person** m_arr;
	int      m_arrSize;
	int      m_k;
	int      m_numOfComp; //Comparisons for rand selections

	//Help functions
	bool idExists   (int amount, int id) const;
	bool isKInRange (int k) const;
	void freeMemory (int amount);

public:
	//C'tors
	 Print(int size);
	 Print(const Print& s) = delete;
	 Print(Print&& s) = delete;
	~Print();

	void readUserInput();

};

#endif //!__PRINT_
