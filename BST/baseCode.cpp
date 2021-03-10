#include "baseCode.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

baseCode::baseCode()
{
	in.open("tree.txt");
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
	displayTree(r->right, x + width, y + 3, width);
	displayTree(r->left, x - width, y + 3, width);
}

void baseCode::readFile() //reads in nodes
{
	Node* temp;
	while (in >> fileNum && fileNum != -1)
	{
		temp = new Node();
		if (count == 0)
		{
			temp->num = fileNum;
			root = temp;
		}
		else
		{
			buildTree(fileNum, root);
		}

		count++;
	}
	in.close();

}

void baseCode::menu()
{
	cout << "########  #### ##    ##    ###    ########  ##    ##    ######## ########  ######## ########    ##     ## ####  ######  ##     ##    ###    ##       #### ########    ###    ######## ####  #######  ##    ##" << endl;
	cout << "##     ##  ##  ###   ##   ## ##   ##     ##  ##  ##        ##    ##     ## ##       ##          ##     ##  ##  ##    ## ##     ##   ## ##   ##        ##       ##    ## ##      ##     ##  ##     ## ###   ##" << endl;
	cout << "##     ##  ##  ####  ##  ##   ##  ##     ##   ####         ##    ##     ## ##       ##          ##     ##  ##  ##       ##     ##  ##   ##  ##        ##      ##    ##   ##     ##     ##  ##     ## ####  ##" << endl;
	cout << "########   ##  ## ## ## ##     ## ########     ##          ##    ########  ######   ######      ##     ##  ##   ######  ##     ## ##     ## ##        ##     ##    ##     ##    ##     ##  ##     ## ## ## ##" << endl;
	cout << "##     ##  ##  ##  #### ######### ##   ##      ##          ##    ##   ##   ##       ##           ##   ##   ##        ## ##     ## ######### ##        ##    ##     #########    ##     ##  ##     ## ##  ####" << endl;
	cout << "##     ##  ##  ##   ### ##     ## ##    ##     ##          ##    ##    ##  ##       ##            ## ##    ##  ##    ## ##     ## ##     ## ##        ##   ##      ##     ##    ##     ##  ##     ## ##   ###" << endl;
	cout << "########  #### ##    ## ##     ## ##     ##    ##          ##    ##     ## ######## ########       ###    ####  ######   #######  ##     ## ######## #### ######## ##     ##    ##    ####  #######  ##    ##" << endl;

	cout << endl;
	cout << "Enter (1) to Display Tree (LNR)" << endl;
	cout << "Enter (2) to Display Tree (NLR)" << endl;
	cout << "Enter (3) to Display Tree (LRN)" << endl;
	cout << "Enter (4) to ADD Number" << endl;
	cout << "Enter (5) to DELETE Number" << endl;
	cout << "Enter (6) to Exit" << endl;
}

void baseCode::menuChoice()
{
	while (1)
	{
		cout << endl << "Enter a Command: ";
		cin >> choice;
		if (choice == '1') //print Tree with LNR order output
		{
			readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "LNR: ";
			LNR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == '2')//print Tree with NLR order output
		{
			readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "NLR: ";
			NLR(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == '3')//print Tree with LRN order output
		{
			readFile();
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl << endl << endl << "LRN: ";
			LRN(root);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == '4') //Prompts user to insert node
		{
			cout << endl << "Enter the Number You Want to Insert: " << endl;
			cin >> addNum;
			ADD(addNum, root);
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl;
		}


		else if (choice == '5') //Prompts user to delete 
		{
			cout << endl << "Enter the Number You Want to Delete: " << endl;
			cin >> removeNum;
			DEL(removeNum, root);
			system("cls");
			menu();
			displayTree(root, 110, 20, 20);
			cout << endl << endl << endl << endl << endl;
		}

		else if (choice == '6')
			exit(0);
	}
}

struct baseCode::Node* baseCode::buildTree(int n, Node* r)
{
	//builds the root
	if (r == nullptr)
	{
		Node* temp = new Node(n);
		return temp;
	}
	else //build the rest of the tree based on whether the nodes are greater or less than their parents
	{
		if (n <= r->num) //if the value is less than the current value, go to the left
		{
			r->left = buildTree(n, r->left);
		}
		else if (n >= r->num) //if the value is greater than the current value, go to the right
		{
			r->right = buildTree(n, r->right);
		}
		return r;
	}

	return nullptr;
}

struct baseCode::Node* baseCode::ADD(int number, Node* n)
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

//Deletes the node input by the user//
struct baseCode::Node* baseCode::DEL(int removeNumber, Node* r)
{
	//base case
	if (r == nullptr)
		return r;

	//if the number we're trying to remove is smaller than the current number we're looking at, it is in the left subtree
	if (removeNumber < r->num)
		r->left = DEL(removeNumber, r->left);

	//if the number we're trying to remove is larger than the current number we're looking at, it is in the right subtree
	else if (removeNumber > r->num)
		r->right = DEL(removeNumber, r->right);

	//Once we've found the node containing the value we're trying to delete, check if the node has 2, 1 or 0 children
	else
	{
		// if the right or left node does not contain a child
		if (r->left == nullptr)
			return r->right;
		else if (r->right == nullptr)
			return r->left;

		// if there is a parent with two children, replace it with the node that is one left, and all the way to the right
		Node* temp = r->left;

		//loop down to find the rightmost leaf
		while (temp->right != nullptr)
			temp = temp->right;

		// take that node and replace its value with the one that is being deleted, then delete the leaf that was used to replace the "delete" node
		r->num = temp->num;
		r->left = DEL(temp->num, r->left);
	}
	return r;
}

int main()
{
	baseCode bc;
	cout << "MAKE SURE TO USE FULL SCREEN WHEN RUNNING THE PROGRAM" << endl;
	Sleep(1000);
	cout << endl << "LOADING...";
	Sleep(2000);
	system("cls");
	bc.menu();
	bc.menuChoice();
	return 0;
}
