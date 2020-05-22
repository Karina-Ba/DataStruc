#include "BSTreeNode.h"

int  BSTreeNode::m_numOfCompsNode = 0;
//--------------------------------------------------------------------------------//
BSTreeNode::BSTreeNode()
{
	this->m_left		  = this->m_left = nullptr;
	this->m_data		  = nullptr;
	this->m_key			  = 0;
	this->m_children	  = 0;
}
//--------------------------------------------------------------------------------//
BSTreeNode::BSTreeNode(int key, Person* data, BSTreeNode * left, BSTreeNode * right)
{
	this->m_key			  = key;
	this->m_data		  = data;
	this->m_left		  = left;
	this->m_right		  = right;
	this->m_children	  = 0;

	if (left) //If there's left child add his amount of children to current node plus 1 for the left child itself
	{
		this->m_children += left->m_children + 1;
	}

	if (right) //Same as above for the right child
	{
		this->m_children += right->m_children + 1;
	}
}
//--------------------------------------------------------------------------------//
BSTreeNode::~BSTreeNode()
{
	if (this->m_left)
	{
		delete this->m_left;
	}

	if (this->m_right)
	{
		delete this->m_right;
	}
}
//--------------------------------------------------------------------------------//
void BSTreeNode::InOrder(int k)
{
	if (this->m_left)
	{
		this->m_left->InOrder(k);
	}

	++BSTreeNode::m_numOfCompsNode;
	if (this->m_data->getId() >= k)
	{
		return;
	}

	cout << *this->m_data << endl;

	if (this->m_right)
	{
		this->m_right->InOrder(k);
	}
}
//--------------------------------------------------------------------------------//
void BSTreeNode::PreOrder()
{
	cout << this->m_data;

	if (this->m_left)
	{
		this->m_left->PreOrder();
	}

	if (this->m_right)
	{
		this->m_right->PreOrder();
	}
}
//--------------------------------------------------------------------------------//
void BSTreeNode::PostOrder()
{
	if (this->m_left)
	{
		this->m_left->PostOrder();
	}

	if (this->m_right)
	{
		this->m_right->PostOrder();
	}

	cout << this->m_data;
}
//--------------------------------------------------------------------------------//