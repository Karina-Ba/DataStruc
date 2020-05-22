#include "BSTree.h"

//--------------------------------------------------------------------------------//
BSTree::BSTree()
{
	this->m_root = nullptr;
}
//--------------------------------------------------------------------------------//
BSTree::~BSTree()
{
	delete this->m_root;
	this->m_root = nullptr;
}
//--------------------------------------------------------------------------------//
BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode* temp = this->m_root;

	while (temp) //While we haven't reached nullptr
	{
		if (key == temp->m_key) //If the key in temp is the same as wanted, return temp and add one to comparison count
		{
			++m_numOfCompBST;
			return temp;
		}

		else if (key < temp->m_key) //If the key is smaller than the one in the temp, forward temp to be left child and add two to comparison, one for before one for this
		{
			m_numOfCompBST += 2;
			temp = temp->m_left;
		}

		else //If reached this point, add two to comparison for conditions above and forward temp to right child
		{
			m_numOfCompBST += 2;
			temp = temp->m_right;
		}
	}

	return nullptr; //If we haven't returned yet, return nullptr not found
}
//--------------------------------------------------------------------------------//
BSTreeNode * BSTree::FindK(int index) //Find the k'th otem in the tree (index posing as k for readibility)
{
	BSTreeNode* temp = this->m_root;
	int tempInd = 1; //Setting the temp index to be 1

	while (temp) //While temp is not nullptr
	{
		if (temp->m_left) //If left child exists index of temp will be left's children + left itself + temp itself
		{
			tempInd = temp->m_left->m_children + 2;
		}
		else //Resetting temp index for next loops of no left child found
		{
			tempInd = 1;
		}

		if (tempInd - 1 >= index) //If the index we're looking for is in the left tree forward temp to be left child
		{
			temp = temp->m_left;
		}

		else if (tempInd == index) //If temp index is the index we want, return temp
		{
			return temp;
		}

		else //haven't found yet, search right tree but exclude the temp index from index now
		{
			index = index - tempInd;
			
			temp = temp->m_right;
		}
	}

	return temp; //Haven't found so return is nullptr (temp because we're out of the loop when temp is nullptr)
}
//--------------------------------------------------------------------------------//
void BSTree::Insert(int key, Person* data)
{ //Did not check if key exists because ID is unique
	BSTreeNode* temp   = this->m_root;
	BSTreeNode* parent = this->m_root;
	BSTreeNode* newNode;
	
	//Find place to input new node
	while (temp) 
	{
		parent = temp;
		
		if (key < temp->m_key)
		{
			temp = temp->m_left;
		}

		else
		{
			temp = temp->m_right;
		}
		parent->m_children++;
		++m_numOfCompBST; //Forward comparisons because of condition
	}

	newNode = new BSTreeNode(key, data, nullptr, nullptr); //Create the node

	if (!parent) //If the parent is nullptr, set the root to be new node
	{
		this->m_root = newNode;
		return;
	}

	else if (key < parent->m_key) //If the key is smaller than parent's key, input as left child and add one to comparisons
	{
		parent->m_left = newNode;
		++m_numOfCompBST;
	}
	 
	else //Else key is bigger or the same as parent, add as right child and add one to comparions for previous condition
	{
		++m_numOfCompBST;
		parent->m_right = newNode;
	}

}
//--------------------------------------------------------------------------------//
void BSTree::Delete(int key)
{
	if (!this->m_root || !Find(key)) //If tree is empty or key doesn't exists return
	{
		return;
	}

	BSTreeNode* temp   = this->m_root;
	BSTreeNode* parent = this->m_root;
	BSTreeNode* max;

	//While we haven't reached the needed key forward temp and search the corresponding tree while adding one to comparisons for each condition and subtracting one from amount of children
	while (temp->m_key != key) 
	{
		parent = temp;

		if (key < temp->m_key)
		{
			temp = temp->m_left;
		}

		else
		{
			temp = temp->m_right;
		}

		++m_numOfCompBST;
		parent->m_children--;
	}

	if (!temp->m_right) //Either 0 or 1 children in binary tree
	{
		if (temp->m_left) //For a child on left and zero children on right
		{
			if (parent->m_left == temp) //If the left one is temp fix the pointers and children amount
			{
				parent->m_left = temp->m_left;
				parent->m_children = temp->m_children; 
			}

			else //Same as above is it's the right  one
			{
				parent->m_right = temp->m_left;
				parent->m_children = temp->m_children; //No need to add right amount of children
			}
		}

		delete temp; //Delete the node
	}

	else //2 children
	{
		max = temp; //Set max t be temp

		while (max->m_right) //Find the max in the left tree
		{
			parent = max;
			--parent->m_children;
			max = max->m_right;
		}
		
		if (max) //If found max, input it's content into temp and subtract one from children amount since we will delete it
		{
			temp->m_key  = max->m_key;
			temp->m_data = max->m_data;
			--temp->m_children;

			if (parent->m_left == max) //Same as with 1 or 0 children
			{
				parent->m_left = max->m_left;
			}

			else
			{
				parent->m_right = max->m_left;
			}

			delete max; //Delete that node
		}
	}
}
//--------------------------------------------------------------------------------//
BSTreeNode * BSTree::Min(BSTreeNode *root, BSTreeNode * parent) //Find min
{
	if (!root) //If tree is empty return nullptr
	{
		return nullptr;
	}

	BSTreeNode* temp = this->m_root;
	parent = this->m_root;

	while (temp->m_left) //Reach left most child who is smallest
	{
		parent = temp;

		temp = temp->m_left;
	}

	return temp;
}
//--------------------------------------------------------------------------------//
BSTreeNode * BSTree::Max(BSTreeNode * root, BSTreeNode * parent) //Find max
{
	if (!root) //If tree is empty return nullptr
	{
		return nullptr;
	}

	BSTreeNode* temp = this->m_root;
	parent = this->m_root;

	while (temp->m_right) //Reach right most child who is smallest
	{
		parent = temp;

		temp = temp->m_right;
	}

	return temp;
}
//--------------------------------------------------------------------------------//
void BSTree::PrintTree(int k)
{
	if (this->m_root)
	{
		this->m_root->InOrder(k);
		this->m_numOfCompBST += this->m_root->m_numOfCompsNode;
	}
	cout << endl;
}
//--------------------------------------------------------------------------------//
int BSTree::getNumOfCompBST()
{
	return this->m_numOfCompBST;
}
//--------------------------------------------------------------------------------//
