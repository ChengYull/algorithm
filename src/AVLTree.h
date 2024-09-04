#pragma once

/*AVL 树节点类*/
struct TreeNode{
	int val{};
	int height = 0;
	TreeNode *left{};
	TreeNode *right{};
	TreeNode() = default;
	explicit TreeNode(int x) :val(x){}
};

class AVLTree{
public:
	TreeNode *root;

	/*获取节点高度*/
	int height(TreeNode *node);
	/*更新节点高度*/
	void updateHeight(TreeNode *node);
	/*获取平衡因子*/
	int balanceFactor(TreeNode *node);
	/*右旋操作*/
	TreeNode *rightRotate(TreeNode *node);
	/*左旋操作*/
	TreeNode *leftRotate(TreeNode *node);
	/*执行旋转操作，使该子树重新恢复平衡*/
	TreeNode *rotate(TreeNode *node);
	/*插入节点*/
	void insert(int val);
	/*递归插入节点（辅助方法）*/
	TreeNode *insertHelper(TreeNode *node, int val);
	/*删除节点*/
	void remove(int val);
	/*递归删除节点（辅助方法）*/
	TreeNode *removeHelper(TreeNode *node, int val);
};