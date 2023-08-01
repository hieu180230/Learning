#pragma once
#include "Node.h"

int height(Node* root)
{
	if (root == NULL) return 0;
	return root->height;
}

int balanceFactor(Node* root)
{
	if (!root) return 0;
	return height(root->left) - height(root->right);
}

