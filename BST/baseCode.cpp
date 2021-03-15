#include "baseCode.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

baseCode::baseCode()
{
	in.open("C:\\tree.txt");
	count = 0;

}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void baseCode::LNR(Node* n) //recursively prints tree in LNR order
{
	if (n->left != nullptr)
		LNR(n->left);
	cout << n->num << " ";
	if (n->right != nullptr)
		LNR(n->right);
}

void baseCode::NLR(Node* n) //recursively prints tree in NLR order
{
	cout << n->num << " ";
	if (n->left != nullptr)
		NLR(n->left);
	if (n->right != nullptr)
		NLR(n->right);
}

void baseCode::LRN(Node* n) //recursively prints tree in LRN order
{
	if (n->left != nullptr)
		LRN(n->left);
	if (n->right != nullptr)
		LRN(n->right);
	cout << n->num << " ";
}

void baseCode::displayTree(Node* r, int x, int y, int width)
{
	if (r == nullptr)
		return;
	if (r == root)
	{
		gotoxy(x - 1, y - 1);
		cout << "root";
	}
	gotoxy(x, y);
	//if node has 2 children
	if (r->left != nullptr && r->right != nullptr)
	{
		cout << r->num;
		gotoxy(x - 18, y + 1);
		cout << "__________________||__________________";
		gotoxy(x - 18, y + 2);
		cout << "|                                     |";
	}
	//if theres only a left child
	else if (r->left != nullptr && r->right == nullptr)
	{
		cout << r->num;
		gotoxy(x - 18, y + 1);
		cout << "___________________|";
		gotoxy(x - 18, y + 2);
		cout << "|                   ";
	}
	//if there's only a right child
	else if (r->left == nullptr && r->right != nullptr)
	{
		cout << r->num;
		gotoxy(x, y + 1);
		cout << "|__________________";
		gotoxy(x, y + 2);
		cout << "                   |";
	}
	else {
		cout << r->num;
	}
	//Sleep(1500);
	displayTree(r->right, x + width, y + 3, width/2);
	displayTree(r->left, x - width, y + 3, width/2);
}

//void baseCode::readFile() //reads in nodes
//{
//	Node* temp;
//	while (in >> fileNum && fileNum != -1)
//	{
//		temp = new Node();
//		if (count == 0)
//		{
//			temp->num = fileNum;
//			root = temp;
//		}
//		else
//		{
//			buildTree(fileNum, root);
//		}
//
//		count++;
//	}
//	in.close();
//
//}

void baseCode::menu()
{
	//cout << "   #    #     # #          #######                      " << endl;
	//cout << "  # #   #     # #             #    #####  ###### ###### " << endl;
	//cout << " #   #  #     # #             #    #    # #      #      " << endl;
	//cout << "#     # #     # #             #    #    # #####  #####  " << endl;
	//cout << "#######  #   #  #             #    #####  #      #      " << endl;
	//cout << "#     #   # #   #             #    #   #  #      #      " << endl;
	//cout << "#     #    #    #######       #    #    # ###### ###### " << endl << endl;



	cout << "--------------------------------------------------------------------------- \n" <<
		"         AVL Tree Implemenation \n" <<
		"A: Insert an integer to tree and show the balanced tree at each insertion. \n" <<
		"B: Display the balanced tree and show preorder traversal. \n" <<
		"C: Display the balanced tree and show inorder traversal \n" <<
		"D: Display the balanced tree and show postorder traversal \n" <<
		"E: Exit \n";
}

void baseCode::menuChoice()
{
	while (1)
	{
		cout << endl << "Enter a Command: ";
		cin >> choice;

		if (choice == 'A' || choice == 'a') //Prompts user to insert node
		{
			cout << endl << "Enter the Number You Want to Insert: " << endl;
			cin >> addNum;
			buildTree(addNum, root);
			//checkBalMain(root);
			//balanceTree(root);
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl;
		}
		else if (choice == 'B' || choice == 'b') //print Tree with LNR order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "LNR: ";
			LNR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == 'C' || choice == 'c')//print Tree with NLR order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "NLR: ";
			NLR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == 'D' || choice == 'd')//print Tree with LRN order output
		{
			//readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "LRN: ";
			LRN(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == 'E' || choice == 'e')
			exit(0);
	}
}

struct baseCode::Node* baseCode::buildTree(int n, Node* r)
{
	//builds the root
	if (r == nullptr)
	{
		Node* temp = new Node(n);
		if (root == nullptr)
			root = temp;
		//else if (temp->left == root || temp->right == root)
			//root = temp;
		return temp;
	}
	//build the rest of the tree based on whether the nodes are greater or less than their parents
	if (n < r->num) //if the value is less than the current value, go to the left
		r->left = buildTree(n, r->left);
	else if (n > r->num) //if the value is greater than the current value, go to the right
		r->right = buildTree(n, r->right);
	else
		return r;

	int balanceFactor = Difference(r);

	if (balanceFactor > 1) // Left subtree is taller
	{
		if (Difference(r->left) > 0)
			return rightRightRotate(r);
		else
			return leftRightRotate(r);
	}
	else if (balanceFactor < -1) // Right subtree is taller
	{
		if (Difference(r->right) < 0)
			return leftLeftRotate(r);
		else
			return rightLeftRotate(r);
	}
	else
		return r;
}

struct baseCode::Node* baseCode::ADD(int number, Node * n)
{
	//if reached a node that is null, create a leaf with the value you want to add
	if (n == nullptr)
	{
		Node* leaf = new Node(number);
		return leaf;
	}
	else
	{
		//Go down tree if the value hasnt been found
		if (number < n->num)
			n->left = ADD(number, n->left);
		else if (number > n->num)
			n->right = ADD(number, n->right);
		return(n);
	}
	return nullptr;
}

struct baseCode::Node* baseCode::leftLeftRotate(Node * r)
{
	//Returns the tree node resulting from
	// a left rotation.
	Node* S = r->right;
	Node* B = S->left;
	S->left = r;
	r->right = B;
	return S;
}

struct baseCode::Node* baseCode::rightRightRotate(Node * r)
{
	// Returns the tree node resulting from
	// a right rotation.
	Node* S = r->left;
	Node* B = S->right;
	S->right = r;
	r->left = B;
	return S;
}

struct baseCode::Node* baseCode::leftRightRotate(Node * r)
{
	// Returns the tree node resulting from a
	// right-left rotation.
	Node* S = r->left;
	r->left = leftLeftRotate(S);
	return rightRightRotate(r);
}

struct baseCode::Node* baseCode::rightLeftRotate(Node * r)
{
	// Returns the tree node resulting from a
	// right-left rotation.
	Node* S = r->right;
	r->right = rightRightRotate(S);
	return leftLeftRotate(r);
}

struct baseCode::Node* baseCode::balanceTree(Node * r)
{
	int balanceFactor = Difference(r);

	if (balanceFactor > 1) // Left subtree is taller
	{
		if (Difference(r->left) > 0)
			return rightRightRotate(r);
		else
			return leftRightRotate(r);
	}
	else if (balanceFactor < -1) // Right subtree is taller
	{
		if (Difference(r->right) < 0)
			return leftLeftRotate(r);
		else
			return rightLeftRotate(r);
	}
	else
		return r;
}

int baseCode::Difference(Node * r)
{
	return (height(r->left) - height(r->right));
}

int baseCode::height(Node * r) const
{
	if (r == nullptr)
		return 0;
	else
	{
		int heightLeft = height(r->left);
		int heightRight = height(r->right);
		if (heightLeft > heightRight)
			return heightLeft + 1;
		else
			return heightRight + 1;
	}
}

//Deletes the node input by the user//
//struct baseCode::Node* baseCode::DEL(int removeNumber, Node* r)
//{
//	//base case
//	if (r == nullptr)
//		return r;
//
//	//if the number we're trying to remove is smaller than the current number we're looking at, it is in the left subtree
//	if (removeNumber < r->num)
//		r->left = DEL(removeNumber, r->left);
//
//	//if the number we're trying to remove is larger than the current number we're looking at, it is in the right subtree
//	else if (removeNumber > r->num)
//		r->right = DEL(removeNumber, r->right);
//
//	//Once we've found the node containing the value we're trying to delete, check if the node has 2, 1 or 0 children
//	else
//	{
//		// if the right or left node does not contain a child
//		if (r->left == nullptr)
//			return r->right;
//		else if (r->right == nullptr)
//			return r->left;
//
//		// if there is a parent with two children, replace it with the node that is one left, and all the way to the right
//		Node* temp = r->left;
//
//		//loop down to find the rightmost leaf
//		while (temp->right != nullptr)
//			temp = temp->right;
//
//		// take that node and replace its value with the one that is being deleted, then delete the leaf that was used to replace the "delete" node
//		r->num = temp->num;
//		r->left = DEL(temp->num, r->left);
//	}
//	return r;
//}

void baseCode::checkBalMain(Node * temp)
{
	int h = height(temp);
	int i;
	for (i = 1; i <= h; i++)
		checkBal(temp, i);
}

/* Print nodes at a given level */
void baseCode::checkBal(Node * temp, int level)
{
	if (temp == NULL)
		return;

	//BALANCE FUNCTION
	if (level > 2)
	{
		checkBal(temp->left, level - 1);
		checkBal(temp->right, level - 1);
	}
}

int main()
{
	baseCode bc;
	cout << "MAKE SURE TO USE FULL SCREEN WHEN RUNNING THE PROGRAM" << endl;
	Sleep(1000);
	cout << endl << "LOADING...";
	Sleep(1000);
	system("cls");
	bc.menu();
	bc.menuChoice();
	return 0;
}
