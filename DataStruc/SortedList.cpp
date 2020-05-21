#include "SortedList.h"

//-------------------------------------------------------------------------------------------//
SortedList::SortedList()
{
	this->m_head = this->m_tail = nullptr;
	this->m_numOfCompLst = 0;
}
//-------------------------------------------------------------------------------------------//
SortedList::~SortedList()
{
	this->makeEmpty();
}
//-------------------------------------------------------------------------------------------//
SortedList::ListNode* SortedList::getHead() const
{
	return this->m_head;
}
//-------------------------------------------------------------------------------------------//
SortedList::ListNode* SortedList::getTail() const
{
	return this->m_tail;
}
//-------------------------------------------------------------------------------------------//
int SortedList::getNumOfCompLst() const
{
	return this->m_numOfCompLst;
}
//-------------------------------------------------------------------------------------------//
void SortedList::setHead(ListNode* head)
{
	this->m_head = head;
}
//-------------------------------------------------------------------------------------------//
void SortedList::setTail(ListNode* tail)
{
	this->m_tail = tail;
}
//-------------------------------------------------------------------------------------------//
ostream& operator<< (ostream& os, const SortedList& list)
{
	SortedList::ListNode* node = list.m_head;
	while (node != nullptr)
	{
		os << *node->getItem() << endl;
		node = node->getNext();
	}
	return os;
}
//-------------------------------------------------------------------------------------------//
bool SortedList::isEmpty()
{
	return (this->m_head == nullptr && this->m_tail == nullptr);
}
//-------------------------------------------------------------------------------------------//
void SortedList::makeEmpty()
{
	ListNode *prev = this->m_head;
	ListNode *curr = prev;

	//Go over the list and delete ListNodes
	while (curr)
	{
		prev = curr;
		curr = curr->getNext();
		delete prev;
	}

	this->m_head = this->m_tail = nullptr;
}
//-------------------------------------------------------------------------------------------//
void SortedList::addItem(Person* item)
{
	ListNode* node = new ListNode(item);

	if (this->isEmpty())
	{
		this->m_head = this->m_tail = node;
	}
	else
	{
		if (*item >= *this->m_tail->m_item)
		{
			++this->m_numOfCompLst;
			this->m_tail->m_next = node;
			this->m_tail = node;
		}
		else if (*this->m_head->m_item >= *item)
		{
			this->m_numOfCompLst += 2;
			node->m_next = this->m_head;
			this->m_head = node;
		}
		else
		{
			this->m_numOfCompLst += 2;
			ListNode* currentNode = this->m_head;

			while (currentNode->m_next != nullptr)
			{
				if (*currentNode->m_next->m_item > *node->m_item)
				{
					node->m_next = currentNode->m_next;
					currentNode->m_next = node;
					break;
				}
				else
				{
					currentNode = currentNode->m_next;
				}
				++this->m_numOfCompLst;
			}
		}
	}
}
//-------------------------------------------------------------------------------------------//