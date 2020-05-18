#ifndef __BSTREE_
#define __BSTREE_

#include "Utils.h"
#include "BSTreeNode.h"

class BSTree
{
private:
	BSTreeNode* m_root;

	static int CMP_NUM_BST; //Comparisons for binary search tree

public:
	 BSTree();
	 BSTree(const BSTree& other) = delete;
	 BSTree(BSTree&& other)      = delete;
	~BSTree();

	//All the tree functions excluding pred and succ
	BSTreeNode* Find (int key);
	BSTreeNode* FindK(int index);
	void Insert (int key, int plc, Person* data);
	void Delete (int key);
	BSTreeNode* Min(BSTreeNode* root, BSTreeNode* parent); //Parent var is for returning the parent
	BSTreeNode* Max(BSTreeNode* root, BSTreeNode* parent);
	void PrintTree();

	//Get functions
	static int getCmpNumBST();

};

#endif //!__BSTREE_