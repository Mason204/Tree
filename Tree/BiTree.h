/*
Mason Henry
Data Structures
Due: 4/18/20
Create a binary tree class which will sort integers in order of least to greatest and greatest to least.
*/
#ifndef BITREE_H
#define BITREE_H

//Treenode structure
struct TreeNode
{
	int info;
	TreeNode* left;
	TreeNode* right;
};

class BiTree
{
public:
	//Constructor
	BiTree();
	//Destructor
	~BiTree();

	//Pre: Tree must have been constructed.
	//Post: Calls the Ascending print private function to print numbers in ascending order.
	void Print();
	//Pre: Tree must have been constructed.
	//Post: Calls the TreePrint private function to print numbers in a tree format.
	void TPrint();
	//Pre: Tree must have been constructed.
	//Post: Calls the DescendingPrint private function to print numbers in descending order.
	void RPrint();
	//Pre: Tree must have been constructed.
	//Post: Calls the Insert private function to insert an item into the tree.
	void InsertItem(int item);
	//Pre: Tree must have been constructed
	//Post: Calls the Delete private function to delete a specific number out of the tree. 
	void DeleteItem(int item);
	//Pre: Tree must have been constructed.
	//Post: Returns true if tree is empty and false if it is not.
	bool IsEmpty();
	//Pre: Tree must have been constructed.
	//Post: Returns true if Nothing else can be added to the tree and false if you can.
	bool IsFull();
	//Pre: Tree must have been constructedf.
	//Post: Calls the MakeEmpty private function and deletes all the items from the tree.
	void MakeEmptyPublic();

private:
	//The starting node for the tree.
	TreeNode* root;	
	//Used for spacing when outputing in tree format.
	int space = 0;

	//Pre: Tree must have been constructed and InsertItem function must have been called.
	//Post: Inserts and item into the tree.
	void Insert(TreeNode* &node, int item);
	//Pre: Tree must have been constructed and DeleteItem function msut have been called.
	//Post: Deletes a specific item from the tree.
	void Delete(TreeNode* &node, int item);
	//Pre: Tree must have been constructed and Delete function must have been called by DeleteItem.
	//Post: Does the actual deleting of the tree node and makes sure to properly link the nodes together.
	void DeleteNode(TreeNode* &node);
	//Pre: Tree must have been constructed and Print function must have been called.
	//Post: Prints the tree in ascending order to the screen.
	void AscendingPrint(TreeNode* &node);
	//Pre: Tree must have been constructed and RPrint function must have been called.
	//Post: Prints the tree in descending order to the screen.
	void DescendingPrint(TreeNode* &node);
	//Pre: Tree must have been constructed and Tprint function must have been called.
	//Post: Prints the tree in the tree format with the root being the one on the farthest left to the screen.
	void TreePrint(TreeNode*& node, int space);
	//Pre: Tree must have been constructed and MakeEmptyPublic function must have been called.
	//Post: Deletes the nodes from the tree.
	void MakeEmpty(TreeNode*& node);
};

#endif
