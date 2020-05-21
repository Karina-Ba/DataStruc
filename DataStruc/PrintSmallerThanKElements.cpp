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
//Partition algorithem like the second algorithem from the book, meaning it has more conditions that are strangers to each other concluding in a bigger
// amount of comparisons for the randSelection but I chose this algorithem because of it's readibility, as they both have ?(n) run time efficiency

	int pivot = left;

	if(left < right) //If left is smaller than right, add one to left
		++left;

	while (left < right) //As long as they are different
	{
		++this->m_numOfComp; //Adding one to comparisons for the condition after them
		if (*(m_arr[left]) > *(m_arr[right])) //If left item bigger than right, swap them (using the swap in the library)
		{
			swap(m_arr[left], m_arr[right]);
		}
		++this->m_numOfComp;
		if (*(m_arr[left]) < *(m_arr[pivot])) //If left is smaller than the item in pivot, forward left
		{
			left++;
		}
		++this->m_numOfComp;
		if (*(m_arr[right]) > *(m_arr[pivot])) //If right is bigger than pivot, take right back one
		{
			--right;
		}
	}

	++this->m_numOfComp;

	if (*(m_arr[left]) > *(m_arr[pivot])) //If the last left is bigger than pivot, take one step back which is conditionally smaller than pivot item
	{
		left--;
	}
	swap(m_arr[pivot], m_arr[left]); //Swap them
	pivot = left;

	return pivot;
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
		if (this->m_arr[i]->getId() < this->m_k)
		{
			++this->m_numOfComp;
			lst.addItem(this->m_arr[i]);
		}
	}
	this->m_numOfComp += lst.getNumOfCompLst();
	cout << lst << endl;
	cout << "NaivePrint: " << this->m_numOfComp << " comparisons" << endl;
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

	this->m_numOfComp += tree.getNumOfCompBST();
	tree.PrintTree(this->m_k);
	cout << "BSTPrint: " << this->m_numOfComp << " comparisons" << endl;
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
	cout << "PrintBySort: " << this->m_numOfComp << " comparisons" << endl;
	this->m_numOfComp = 0;

}
//--------------------------------------------------------------------------------//