
#include "BinarySearchTree.h"
/*查找节点*/
TreeNode* BinarySearchTree::search(int num){
	TreeNode* cur = root;
	while (cur != nullptr){
		// 目标节点在右子树中
		if (cur->val < num){
			cur = cur->right;
		}
		// 目标节点在左子树中
		else if (cur->val > num){
			cur = cur->left;
		}
		// 找到目标节点，跳出循环
		else{
			break;
		}
	}
	// 返回目标节点 ，未找到返回nullptr
	return cur;
}

/*插入节点*/
void BinarySearchTree::insert(int num){
	// 树为空 则初始化根节点
	if (root == nullptr){
		root = new TreeNode(num);
		return;
	}
	
	TreeNode * cur = root;
	TreeNode * pre = nullptr;
	while (cur != nullptr){
		pre = cur;
		if (cur->val < num){
			// 值大于节点 应放右子树中
			cur = cur->right;
		}
		else if (cur->val > num){
			// 值小于节点 应放左子树中
			cur = cur->left;
		}
		else{
			// 重复 该值已存在
			return;
		}
	}
	// 插入节点
	TreeNode * node = new TreeNode(num);
	if (pre->val < num){
		pre->right = node;
	}
	else{
		pre->left = node;
	}
}

/*删除节点*/
void BinarySearchTree::remove(int num){
	// 如果树为空 提前返回
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
	// 未找到删除节点，则直接返回
	if (cur == nullptr)
		return;
	// 子节点数量为 0 或 1
	if (cur->left == nullptr || cur->right == nullptr){
		// nullptr 或者 该子节点
		TreeNode*child = cur->left == nullptr ? cur->right : cur->left;
		// 删除节点cur
		if (cur != root){
			if (pre->left == cur)
				pre->left = child;
			else
				pre->right = child;
			
		}else{
			// 删除节点为根节点，则重新指定根节点
			root = child;
		}
		// 释放内存
		delete cur;
	}
	// 子节点数量为 2
	else {
		// 获取中序遍历中cur的下一个节点
		TreeNode *tmp = cur->right;
		while (tmp->left != nullptr){
			tmp = tmp->left;
		}
		int tmpVal = tmp->val;
		// 递归删除节点tmp
		remove(tmp->val);
		// 用tmp覆盖cur
		cur->val = tmpVal;
	}
}