#ifndef __PRINTSMALLERTHANKELEMENTS_
#define __PRINTSMALLERTHANKELEMENTS_

#include "BSTree.h"
#include "SortedList.h"

class PrintSmallerThanKElements
{
	Person** m_arr;
	int      m_arrSize;
	int      m_k;
	int      m_numOfComp; //Comparisons for printing elements that are smaller than K.

	//Help functions
	bool idExists   (int amount, int id) const;
	void freeMemory (int amount);
	int  partition(int left, int right);
	void quickSort(int left, int right);
	
public:
	//C'tors
	 PrintSmallerThanKElements (int size);
	 PrintSmallerThanKElements (const PrintSmallerThanKElements& s) = delete;
	 PrintSmallerThanKElements (PrintSmallerThanKElements&& s) = delete;
	~PrintSmallerThanKElements ();

	//Getters
	Person** getPersonsArr();
	int      getArrSize();
	int		 getK();
	int		 getNumComparisons();

	//Setters
	void setPersonsArr(Person** pArr);
	void setArrSize(int size);
	void setK(int k);
	void setNumComparisons(int numOfComp);

	void readUserInput();
	void NaivePrint();
	void BSTPrint();
	void PrintBySort();


};

#endif // __PRINTSMALLERTHANKELEMENTS_
