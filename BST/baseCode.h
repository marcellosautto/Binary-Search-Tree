#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class baseCode
{
public:
	struct Node {
		Node* left;
		Node* right;
		int num;
		Node()
		{
			left = nullptr;
			right = nullptr;
			num = 0;
		};
		Node(int number)
		{
			left = nullptr;
			right = nullptr;
			num = number;
		};
	}*root;

	baseCode();
	void LNR(Node* n),
		NLR(Node* n),
		LRN(Node* n),
		readFile(),
		menu(),
		menuChoice(),
		displayTree(Node* r, int x, int y, int width);
	struct Node* buildTree(int n, Node* r);
	struct Node* ADD(int number, Node* n);
	struct Node* DEL(int removeNumber, Node* r);
	int fileNum, count, addNum, removeNum, tempNum;
	char choice;

	ifstream in;
};

