#pragma once

/*AVL ���ڵ���*/
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

	/*��ȡ�ڵ�߶�*/
	int height(TreeNode *node);
	/*���½ڵ�߶�*/
	void updateHeight(TreeNode *node);
	/*��ȡƽ������*/
	int balanceFactor(TreeNode *node);
	/*��������*/
	TreeNode *rightRotate(TreeNode *node);
	/*��������*/
	TreeNode *leftRotate(TreeNode *node);
	/*ִ����ת������ʹ���������»ָ�ƽ��*/
	TreeNode *rotate(TreeNode *node);
	/*����ڵ�*/
	void insert(int val);
	/*�ݹ����ڵ㣨����������*/
	TreeNode *insertHelper(TreeNode *node, int val);
	/*ɾ���ڵ�*/
	void remove(int val);
	/*�ݹ�ɾ���ڵ㣨����������*/
	TreeNode *removeHelper(TreeNode *node, int val);
};