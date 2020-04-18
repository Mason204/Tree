/*
Mason Henry
Data Structures
Due: 4/18/20
Create a binary tree class which will print integers in order of least to greatest and greatest to least and in tree format.
*/
#include "BiTree.h"
#include <iostream>

using namespace std;

BiTree::BiTree()
{
	root = nullptr;
}

BiTree::~BiTree()
{
	MakeEmptyPublic();
}

void BiTree::Insert(TreeNode* &node, int item)
{
	//If the node is null sets it to new, inserts the item, and makes the left and right pointers equal to null.
	if (node == nullptr)
	{
		node = new TreeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->info = item;
	}
	//if the node is not null checks to see whether the item is less than or greater than/equal to and calls insert again at
	//that node.
	else if (item < node->info)
		Insert(node->left, item);
	else
		Insert(node->right, item);
}

void BiTree::Delete(TreeNode* &node, int item)
{
	//Moves down the tree either left or right calling delete each time until the item is equal to the node info and then
	//calls node to properly delete the function.
	if (item < node->info)
		Delete(node->left, item);
	else if (item > node->info)
		Delete(node->right, item);
	else
	{
		DeleteNode(node);
	}
}

void BiTree::DeleteNode(TreeNode* &node)
{
	TreeNode* temp = node;
	TreeNode* parent = nullptr;
	//If both the left and right branch are null, simply deletes the pointer.
	if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
	}	
	//If the left node is null but the right is not.
	else if (node->left == nullptr && node->right != nullptr)
	{
		//changes the node info to the node on the right's info.											//		42			If you want to delete 42 moves					
		node->info = node->right->info;																		//	      \			47 to 42 position and then points
		//sets the temp equal to the right node																//			47		to 45 and 48 as left and right					  
		temp = node->right;																					//		   /  \		and then deletes the node that
		//Points the node to the right node's left and right node if there was any values stored there.		//		  45   48	was the original 47 position.
		node->left = node->right->left;
		node->right = node->right->right;
		//Deletes the node on the right since the value was moved to the starting node.
		delete temp;
	}
	//Same as previous except flips it so that it does it to the left node.
	else if (node->left != nullptr && node->right == nullptr)
	{
		node->info = node->left->info;
		temp = node->left;
		node->right = node->left->right;
		node->left = node->left->left;
		delete temp;
	}
	//If both left and right node have value finds the goes to the right branch and finds the farthest left value and puts the
	//value in the node spot. Then has the node previous to that farthest left node point to the right node off of the 
	//farthest left so that it no longer points to the farthest left node then deletes that node.
	else
	{
		temp = node->right;
		while (temp->left != nullptr)
		{
			parent = temp;
			temp = temp->left;
		}
		parent->left = temp->right;
		node->info = temp->info;
		delete temp;
	}
}

void BiTree::AscendingPrint(TreeNode*& node)
{
	if (node != nullptr)
	{
		//Keeps going down left as far as you can go and then prints that value first.
		if (node->left != nullptr)
			AscendingPrint(node->left);
		//As it works its way back up the tree goes right and prints those values before going up to the previous level.
		cout << node->info << " ";
		if (node->right != nullptr)
			AscendingPrint(node->right);
	}
}

void BiTree::DescendingPrint(TreeNode*& node)
{
	//Same as AscendingPrint except it is reversed so it goes to the right before going left.
	if (node != nullptr)
	{
		if (node->right != nullptr)
			AscendingPrint(node->right);
		cout << node->info << " ";
		if (node->left != nullptr)
			AscendingPrint(node->left);
	}
}

void BiTree::TreePrint(TreeNode*& node, int space)
{
	//Prints the tree out sideways so the that the root is farthest left.
	if (node != nullptr)
	{
		space += 5;
		TreePrint(node->right, space);
		for (int i = 5; i < space; i++)
			cout << " ";
		cout << node->info << endl;
		TreePrint(node->left, space);
	}

}

void BiTree::Print()
{
	AscendingPrint(root);
	cout << endl;
}

void BiTree::TPrint()
{
	TreePrint(root, space);
}

void BiTree::RPrint()
{
	DescendingPrint(root);
	cout << endl;
}

void BiTree::InsertItem(int item)
{
	Insert(root, item);
}

void BiTree::DeleteItem(int item)
{
	Delete(root, item);
}

void BiTree::MakeEmpty(TreeNode*& node)
{
	//Makes way down the tree to the left like it was going to print in ascending order except as it comes
	//back up it deletes the nodes instead of outputing the values.
	if (!IsEmpty()) 
	{
		if (node->left != nullptr)
			MakeEmpty(node->left);
		if (node->right != nullptr)
			MakeEmpty(node->right);
		delete node;
	}
	//When it deletes all other nodes sets the root to null.
	else
		root = nullptr;
}

bool BiTree::IsEmpty()
{
	//Checks to see if the first node, root is null or not.
	if (root == nullptr)
		return true;
	return false;
}

bool BiTree::IsFull()
{
	//Try catch statement to see if a new tree node is able to be created.
	try
	{
		TreeNode* temp = new TreeNode;

		delete temp;
		return false;
	}
	catch (bad_alloc e)
	{
		return true;
	}
}

void BiTree::MakeEmptyPublic()
{
	MakeEmpty(root);
}
