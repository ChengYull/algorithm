#pragma once

#include "AVLTree.h"
class BinarySearchTree{
	
public:
	TreeNode *root;
	/*���ҽڵ�*/
	TreeNode *search(int num);
	/*����ڵ�*/
	void insert(int num);
	/*ɾ���ڵ�*/
	void remove(int num);
};