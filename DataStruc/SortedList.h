#ifndef __SORTEDLIST_H
#define __SORTEDLIST_H

#include "Person.h"

//List as asked in the assignment, list that sorts automatically item is added.
class SortedList
{
private:
	//Nested node class
	class ListNode
	{
	private:
		friend class SortedList;

		Person* m_item;
		ListNode* m_next;

		ListNode(Person* item, ListNode* next = nullptr) : m_item(item), m_next(next) {}
		ListNode(const ListNode& other) = delete; // Disable copy c'tor
		ListNode(ListNode&&) = delete;
		~ListNode() = default;

	public:
		Person* getItem() const { return m_item; }
		ListNode* getNext() const { return m_next; }
	};

private:
	ListNode*  m_head;
	ListNode*  m_tail;
	int        m_numOfCompLst;


public:
	//C'tors
	SortedList();
	SortedList(const SortedList&) = delete;
	SortedList(SortedList&&) = default;
	~SortedList();

	//Getters
	ListNode* getHead() const;
	ListNode* getTail() const;
	int       getNumOfCompLst() const;

	//Setters
	void setHead(ListNode* head);
	void setTail(ListNode* tail);

	//Methods
	bool isEmpty();
	void makeEmpty();
	void addItem(Person* item);

	//Operators
	friend ostream& operator<< (ostream& os, const SortedList& list);
};

#endif // __SORTEDLIST_H
