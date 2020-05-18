#include "BSTreeNode.h"

//--------------------------------------------------------------------------------//
BSTreeNode::BSTreeNode()
{
	this->m_left     = this->m_left = nullptr;
	this->m_data     = nullptr;
	this->m_key      = 0;
	this->m_plc      = 0;
	this->m_children = 0;
}
//--------------------------------------------------------------------------------//
BSTreeNode::BSTreeNode(int key, int plc, Person* data, BSTreeNode * left, BSTreeNode * right)
{
	this->m_key      = key;
	this->m_plc      = plc;
	this->m_data     = data;
	this->m_left     = left;
	this->m_right    = right;
	this->m_children = 0;

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
int BSTreeNode::getPlc() const
{
	return this->m_plc;
}
//--------------------------------------------------------------------------------//
void BSTreeNode::InOrder()
{
	if (this->m_left)
	{
		this->m_left->InOrder();
	}

	cout << this->m_data;

	if (this->m_right)
	{
		this->m_right->InOrder();
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