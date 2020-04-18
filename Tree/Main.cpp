/*
Mason Henry
Data Structures
Due: 4/18/20
Create a binary tree class which will sort integers in order of least to greatest and greatest to least.
*/

#include <iostream>
#include "BiTree.h"

using namespace std;

int main()
{
	BiTree Tree;

	Tree.InsertItem(42);
	Tree.InsertItem(37);
	Tree.InsertItem(55);
	Tree.InsertItem(2);
	Tree.InsertItem(66);
	Tree.InsertItem(57);
	Tree.InsertItem(47);

	Tree.Print();
	Tree.RPrint();
	Tree.TPrint();

	Tree.DeleteItem(55);

	Tree.Print();
	Tree.RPrint();
	Tree.TPrint();

	return 0;
}