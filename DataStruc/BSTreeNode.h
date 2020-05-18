#ifndef __BSTREE_NODE_
#define __BSTREE_NODE_

#include "Utils.h"
#include "Person.h"

class BSTreeNode
{
private:
	int         m_key;
	int         m_plc;
	int         m_children;

	Person*     m_data;
	BSTreeNode* m_left;
	BSTreeNode* m_right;

	friend class BSTree; //BSTree should be able to use the private variables

public:
	 //C'tors
	 BSTreeNode();
	 BSTreeNode(int key, int plc, Person* data, BSTreeNode* left, BSTreeNode* right);
	 BSTreeNode(const BSTreeNode& other) = delete;
	 BSTreeNode(BSTreeNode&& other)      = delete;
	~BSTreeNode();

	//Function returns the variable place
	int getPlc () const;

	//Generic printing functions
	void InOrder  ();
	void PreOrder ();
	void PostOrder();

};

#endif //!__BSTREE_NODE_

