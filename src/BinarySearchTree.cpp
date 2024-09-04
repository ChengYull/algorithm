
#include "BinarySearchTree.h"
/*���ҽڵ�*/
TreeNode* BinarySearchTree::search(int num){
	TreeNode* cur = root;
	while (cur != nullptr){
		// Ŀ��ڵ�����������
		if (cur->val < num){
			cur = cur->right;
		}
		// Ŀ��ڵ�����������
		else if (cur->val > num){
			cur = cur->left;
		}
		// �ҵ�Ŀ��ڵ㣬����ѭ��
		else{
			break;
		}
	}
	// ����Ŀ��ڵ� ��δ�ҵ�����nullptr
	return cur;
}

/*����ڵ�*/
void BinarySearchTree::insert(int num){
	// ��Ϊ�� ���ʼ�����ڵ�
	if (root == nullptr){
		root = new TreeNode(num);
		return;
	}
	
	TreeNode * cur = root;
	TreeNode * pre = nullptr;
	while (cur != nullptr){
		pre = cur;
		if (cur->val < num){
			// ֵ���ڽڵ� Ӧ����������
			cur = cur->right;
		}
		else if (cur->val > num){
			// ֵС�ڽڵ� Ӧ����������
			cur = cur->left;
		}
		else{
			// �ظ� ��ֵ�Ѵ���
			return;
		}
	}
	// ����ڵ�
	TreeNode * node = new TreeNode(num);
	if (pre->val < num){
		pre->right = node;
	}
	else{
		pre->left = node;
	}
}

/*ɾ���ڵ�*/
void BinarySearchTree::remove(int num){
	// �����Ϊ�� ��ǰ����
	if (root == nullptr){
		return;
	}
	TreeNode *cur = root, *pre = nullptr;
	while (cur != nullptr){
		if (cur->val == num)
			break;
		pre = cur;
		if (cur->val < num){
			cur = cur->right;
		}
		else{
			cur = cur->left;
		}
	}
	// δ�ҵ�ɾ���ڵ㣬��ֱ�ӷ���
	if (cur == nullptr)
		return;
	// �ӽڵ�����Ϊ 0 �� 1
	if (cur->left == nullptr || cur->right == nullptr){
		// nullptr ���� ���ӽڵ�
		TreeNode*child = cur->left == nullptr ? cur->right : cur->left;
		// ɾ���ڵ�cur
		if (cur != root){
			if (pre->left == cur)
				pre->left = child;
			else
				pre->right = child;
			
		}else{
			// ɾ���ڵ�Ϊ���ڵ㣬������ָ�����ڵ�
			root = child;
		}
		// �ͷ��ڴ�
		delete cur;
	}
	// �ӽڵ�����Ϊ 2
	else {
		// ��ȡ���������cur����һ���ڵ�
		TreeNode *tmp = cur->right;
		while (tmp->left != nullptr){
			tmp = tmp->left;
		}
		int tmpVal = tmp->val;
		// �ݹ�ɾ���ڵ�tmp
		remove(tmp->val);
		// ��tmp����cur
		cur->val = tmpVal;
	}
}