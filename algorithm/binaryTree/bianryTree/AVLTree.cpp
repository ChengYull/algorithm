#include "AVLTree.h"
#include "algorithm"
using namespace std;
/*��ȡ�ڵ�߶�*/
int AVLTree::height(TreeNode *node){
	return node == nullptr ? -1 : node->height;
}

/*���½ڵ�߶�*/
void AVLTree::updateHeight(TreeNode *node){
	// �ڵ�߶ȵ�����������߶� + 1
	node->height = max(height(node->left), height(node->right)) + 1;
}

/*��ȡƽ������*/
int AVLTree::balanceFactor(TreeNode *node){
	// �սڵ� ƽ������Ϊ0
	if (node == nullptr)
		return 0;
	// �ڵ�ƽ������ = �������߶� - �������߶�
	return height(node->left) - height(node->right);
}

/*��������*/
TreeNode* AVLTree::rightRotate(TreeNode *node){
	TreeNode *child = node->left;
	TreeNode * grand_child = child->right;
	// ��childΪԭ�㣬�� node ������ת
	child->right = node;
	node->left = grand_child;
	// ���½ڵ�߶�
	updateHeight(node);
	updateHeight(child);
	// ������ת�������ĸ��ڵ�
	return child;
}

/*��������*/
TreeNode *AVLTree::leftRotate(TreeNode *node){
	TreeNode *child = node->right;
	TreeNode *grand_child = child->left;
	// ��childΪԭ�� �� node ������ת
	child->left = node;
	node->right = grand_child;
	// ���½ڵ�߶�
	updateHeight(node);
	updateHeight(child);
	// ������ת�������ĸ��ڵ�
	return child;
}

/*ִ����ת������ʹ���������»ָ�ƽ��*/
TreeNode *AVLTree::rotate(TreeNode *node){
	// ��ȡ�ڵ� node ��ƽ������
	int _balanceFactor = balanceFactor(node);
	// ��ƫ��
	if (_balanceFactor > 1){
		if (balanceFactor(node->left) < 0){
			// ������child������node
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		else{
			// ֱ������
			return rightRotate(node);
		}
	}
	// ��ƫ��
	if (_balanceFactor < -1){
		if (balanceFactor(node->right) > 0){
			// ������child ������node
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		else
		{
			// ֱ������
			return leftRotate(node);
		}
	}
	// ƽ������������ת��ֱ�ӷ���
	return node;
}

/*����ڵ�*/
void AVLTree::insert(int val){
	root = insertHelper(root, val);
}
/*�ݹ����ڵ㣨����������*/
TreeNode *AVLTree::insertHelper(TreeNode *node, int val){
	if (node == nullptr){
		return new TreeNode(val);
	}
	if (node->val < val){
		node->right = insertHelper(node->right, val);
	}
	else if (node->val > val){
		node->left = insertHelper(node->left, val);
	}
	else
		// �ظ��ڵ� ֱ�ӷ���
		return node;
	updateHeight(node); // ���½ڵ�߶�
	// ִ����ת������ʹ���������»ָ�ƽ��
	node = rotate(node);
	// �����������ڵ�
	return node;
}

/*ɾ���ڵ�*/
void AVLTree::remove(int val){
	root = removeHelper(root, val);
}
/*�ݹ�ɾ���ڵ㣨����������*/
TreeNode *AVLTree::removeHelper(TreeNode *node, int val){
	if (node == nullptr){
		return nullptr;
	}
	/*���ҽڵ㲢ɾ��*/
	if (node->val < val){
		node->right = removeHelper(node->right, val);
	}
	else if (node->val > val){
		node->left = removeHelper(node->left, val);
	}
	else{
		// �ӽڵ�����Ϊ0 �� 1
		if (node->left == nullptr || node->right == nullptr){
			TreeNode *child = node->left == nullptr ? node->right : node->left;
			delete node;
			node = child;
		}
		// �ӽڵ�����Ϊ 2
		else{
			// �ҵ���������ĺ�һ���ڵ㣨�������������Ԫ�أ�
			TreeNode *tmp = node->right;
			while (tmp->left != nullptr){
				tmp = tmp->left;
			}
			int tmpVal = tmp->val;
			// �ݹ�ɾ�� (����ֵ�Ǹ��ڵ�)��ɾ���������������Ԫ�ط���ֵ�������������ڵ㣩
			node->right = removeHelper(node->right, tmpVal);
			// �ٸ���ֵ���൱�ڽ�����ɾ����
			node->val = tmpVal;
		}
	}
	updateHeight(node); // ����ÿ�������Ľڵ�߶�
	// ִ����ת������ʹ���������»ָ�ƽ��
	node = rotate(node);
	// ���������ĸ��ڵ�
	return node;
}