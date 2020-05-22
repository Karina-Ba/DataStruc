#include "PrintSmallerThanKElements.h"

//--------------------------------------------------------------------------------//
PrintSmallerThanKElements::PrintSmallerThanKElements(int size)
{
	this->m_arrSize = size;
	this->m_numOfComp = this->m_k = 0;
	this->m_arr = new Person*[size]; // Allocate array
}
//--------------------------------------------------------------------------------//
PrintSmallerThanKElements::~PrintSmallerThanKElements()
{
	for (int i = 0; i < this->m_arrSize; i++)
	{
		delete this->m_arr[i];
	}

	delete[] this->m_arr;
}
//--------------------------------------------------------------------------------//
Person ** PrintSmallerThanKElements::getPersonsArr()
{
	return this->m_arr;
}
//--------------------------------------------------------------------------------//
int PrintSmallerThanKElements::getArrSize()
{
	return this->m_arrSize;
}
//--------------------------------------------------------------------------------//
int PrintSmallerThanKElements::getK()
{
	return this->m_k;
}
//--------------------------------------------------------------------------------//
int PrintSmallerThanKElements::getNumComparisons()
{
	return this->m_numOfComp;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::setPersonsArr(Person** pArr)
{
	this->m_arr = pArr;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::setArrSize(int size)
{
	this->m_arrSize = size;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::setK(int k)
{
	this->m_k = k;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::setNumComparisons(int numOfComp)
{
	this->m_numOfComp = numOfComp;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::readUserInput()
{
	int id;
	string name;

	for (int i = 0; i < this->m_arrSize; ++i)
	{
		cin >> id;

		if (idExists(i, id)) // Duplicated id - invalid input
		{
			cout << "invalid input" << endl;
			freeMemory(i);
			exit(INVALID_INPUT_ERROR);
		}

		cin.ignore(); // Ignore the space
		getline(cin, name);

		this->m_arr[i] = new Person(id, name); // Allocate element
	}

	cin >> this->m_k;
}
//--------------------------------------------------------------------------------//
bool PrintSmallerThanKElements::idExists(int amount, int id) const
{
	for (int i = 0; i < amount; ++i)
	{
		if (this->m_arr[i]->getId() == id) // Match
		{
			return true;
		}
	}

	return false;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::freeMemory(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		delete this->m_arr[i];
	}

	delete[] this->m_arr;
}
//--------------------------------------------------------------------------------//
int PrintSmallerThanKElements::partition(int left, int right)
{
	int randIndex = (rand() % (right - left + 1)) + left; // Get random index for pivot
	int lastSmallerElement = left - 1; // Initialize the index of the last element that smaller than pivot  
	int pivot; // Pivot

	swap(&this->m_arr[right], &this->m_arr[randIndex]); // Put the random pivot at the end of the array
	pivot = this->m_arr[right]->getId(); // Set the pivot

	for (int i = left; i < right; i++)
	{
		// The current element is smaller than the pivot  
		if (this->m_arr[i]->getId() < pivot)
		{
			lastSmallerElement++; // Increment the index of the last smaller element  
			swap(&this->m_arr[lastSmallerElement], &this->m_arr[i]);
		}
		++this->m_numOfComp;; // Count number comparisons of RandSelection algorithm
	}
	swap(&this->m_arr[lastSmallerElement + 1], &this->m_arr[right]); // Put the pivot at his correct location

	return (lastSmallerElement + 1); // Location of pivot
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::swap(Person** a, Person** b) const
{
	Person* temp = *a;
	*a = *b;
	*b = temp;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::quickSort(int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = this->partition(left, right);
		quickSort(left, pivot - 1);
		quickSort(pivot + 1, right);
	}
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::NaivePrint()
{
	SortedList lst;

	for (int i = 0; i < this->m_arrSize; ++i)
	{
		++this->m_numOfComp;
		if (this->m_arr[i]->getId() < this->m_k)
		{
			lst.addItem(this->m_arr[i]);
		}
	}
	this->m_numOfComp += lst.getNumOfCompLst();
	cout << endl;
	cout << lst << endl;
	cout << "NaivePrint: " << this->m_numOfComp << " comparisons" << endl << endl;
	this->m_numOfComp = 0;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::BSTPrint()
{
	BSTree tree;

	for (int i = 0; i < this->m_arrSize; ++i)
	{
		tree.Insert(this->m_arr[i]->getId(), this->m_arr[i]);
	}

	tree.PrintTree(this->m_k);
	this->m_numOfComp += tree.getNumOfCompBST();
	cout << endl;
	cout << "BSTPrint: " << this->m_numOfComp << " comparisons" << endl << endl;
	this->m_numOfComp = 0;
}
//--------------------------------------------------------------------------------//
void PrintSmallerThanKElements::PrintBySort()
{
	this->quickSort(0, this->m_arrSize - 1);

	for (int i = 0; i < this->m_arrSize; ++i)
	{
		++this->m_numOfComp;

		if (this->m_arr[i]->getId() < this->m_k)
		{
			cout << *this->m_arr[i] << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << endl;
	cout << "PrintBySort: " << this->m_numOfComp << " comparisons" << endl << endl;
	this->m_numOfComp = 0;

}
//--------------------------------------------------------------------------------//