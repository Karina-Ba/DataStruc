#ifndef __SELECTION_
#define __SELECTION_

#include "Utils.h"
#include "BSTree.h"

class Selection
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
	 Selection(int size);
	 Selection(const Selection& s) = delete;
	 Selection(Selection&& s) = delete;
	~Selection();

	void readUserInput();

};

#endif //!__SELECTION_
