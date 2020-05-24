#ifndef __BSTREE_
#define __BSTREE_

#include "BSTreeNode.h"

class BSTree
{
private:
	BSTreeNode* m_root;
	int m_numOfCompBST; //Comparisons for binary search tree

public:
	//C'tors
	 BSTree();
	 BSTree(const BSTree& other) = delete;
	 BSTree(BSTree&& other)      = delete;
	~BSTree();

	//All the tree functions excluding pred and succ
	BSTreeNode* Find (int key);
	void Insert (int key, Person* data);
	void Delete (int key);
	BSTreeNode* Min(BSTreeNode* root, BSTreeNode* parent); //Parent var is for returning the parent
	BSTreeNode* Max(BSTreeNode* root, BSTreeNode* parent);
	void PrintTreeInOrder(int k);

	//Get functions
	int getNumOfCompBST();

};

#endif //!__BSTREE_