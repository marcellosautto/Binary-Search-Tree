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
		//readFile(),
		menu(),
		menuChoice(),
		displayTree(Node* r, int x, int y, int width);
	struct Node* buildTree(int n, Node* r);
	struct Node* ADD(int number, Node* n);
	struct Node* rightRightRotate(Node* r);
	struct Node* leftLeftRotate(Node* r);
	struct Node* leftRightRotate(Node* r);
	struct Node* rightLeftRotate(Node* r);
	struct Node* balanceTree(Node* r);
	int Difference(Node* r);
	int height(Node* r) const;
	void checkBalMain(Node* temp);
	void checkBal(Node* temp, int level);
	int fileNum, count, addNum, removeNum, tempNum, leftCount, rightCount, h, maxHeight, heightDifference, bal;
	//struct Node* DEL(int removeNumber, Node* r);
	char choice;

	ifstream in;
};

