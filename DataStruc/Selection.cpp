#include "Selection.h"

//--------------------------------------------------------------------------------//
Selection::Selection(int size)
{
	this->m_arrSize = size;
	this->m_numOfComp = this->m_k = 0;
	this->m_arr = new Person*[size]; // Allocate array
}
//--------------------------------------------------------------------------------//
Selection::~Selection()
{
	for (int i = 0; i < this->m_arrSize; i++)
	{
		delete this->m_arr[i];
	}

	delete[] this->m_arr;
}
//--------------------------------------------------------------------------------//
void Selection::readUserInput()
{
	int id, k;
	string name;

	for (int i = 0; i < this->m_arrSize; i++)
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

	cin >> k;
	if (!isKInRange(k)) // K is not in range of the number of elements in the array - invalid input
	{
		cout << "invalid input" << endl;
		freeMemory(this->m_arrSize);
		exit(INVALID_INPUT_ERROR);
	}

	this->m_k = k;
}
//--------------------------------------------------------------------------------//
bool Selection::idExists(int amount, int id) const
{
	for (int i = 0; i < amount; i++)
	{
		if (this->m_arr[i]->getId() == id) // Match
		{
			return true;
		}
	}

	return false;
}
//--------------------------------------------------------------------------------//
void Selection::freeMemory(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		delete this->m_arr[i];
	}

	delete[] this->m_arr;
}
//--------------------------------------------------------------------------------//
bool Selection::isKInRange(int k) const
{
	return (1 <= k && k <= this->m_arrSize);
}
//--------------------------------------------------------------------------------//