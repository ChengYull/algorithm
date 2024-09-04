#pragma once

#include "AVLTree.h"
class BinarySearchTree{
	
public:
	TreeNode *root;
	/*查找节点*/
	TreeNode *search(int num);
	/*插入节点*/
	void insert(int num);
	/*删除节点*/
	void remove(int num);
};