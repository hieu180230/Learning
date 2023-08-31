#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left = NULL;
	Node* right = NULL;
	int height = 0;
};

void L_Rotate(Node*& root)
{
	Node* newRoot = root->right;
	Node* branch = newRoot->left;
	newRoot->left = root;
	root->right = branch;
	root = newRoot;
}
void R_Rotate(Node*& root)
{
	Node* newRoot = root->left;
	Node* branch = newRoot->right;
	newRoot->right = root;
	root->left = branch;
	root = newRoot;
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

void insert(Node*& root, int input)
{
	if (!root) root = newNode(input);
	else if (input < root->data) insert(root->left, input);
	else if (input > root->data) insert(root->right, input);
	else return;
}
