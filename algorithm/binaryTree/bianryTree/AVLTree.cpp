#include "AVLTree.h"
#include "algorithm"
using namespace std;
/*获取节点高度*/
int AVLTree::height(TreeNode *node){
	return node == nullptr ? -1 : node->height;
}

/*更新节点高度*/
void AVLTree::updateHeight(TreeNode *node){
	// 节点高度等于最高子树高度 + 1
	node->height = max(height(node->left), height(node->right)) + 1;
}

/*获取平衡因子*/
int AVLTree::balanceFactor(TreeNode *node){
	// 空节点 平衡因子为0
	if (node == nullptr)
		return 0;
	// 节点平衡因子 = 左子树高度 - 右子树高度
	return height(node->left) - height(node->right);
}

/*右旋操作*/
TreeNode* AVLTree::rightRotate(TreeNode *node){
	TreeNode *child = node->left;
	TreeNode * grand_child = child->right;
	// 以child为原点，将 node 向右旋转
	child->right = node;
	node->left = grand_child;
	// 更新节点高度
	updateHeight(node);
	updateHeight(child);
	// 返回旋转后子树的根节点
	return child;
}

/*左旋操作*/
TreeNode *AVLTree::leftRotate(TreeNode *node){
	TreeNode *child = node->right;
	TreeNode *grand_child = child->left;
	// 以child为原点 将 node 向左旋转
	child->left = node;
	node->right = grand_child;
	// 更新节点高度
	updateHeight(node);
	updateHeight(child);
	// 返回旋转后子树的根节点
	return child;
}

/*执行旋转操作，使该子树重新恢复平衡*/
TreeNode *AVLTree::rotate(TreeNode *node){
	// 获取节点 node 的平衡因子
	int _balanceFactor = balanceFactor(node);
	// 左偏树
	if (_balanceFactor > 1){
		if (balanceFactor(node->left) < 0){
			// 先左旋child再右旋node
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		else{
			// 直接右旋
			return rightRotate(node);
		}
	}
	// 右偏树
	if (_balanceFactor < -1){
		if (balanceFactor(node->right) > 0){
			// 先右旋child 再左旋node
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		else
		{
			// 直接左旋
			return leftRotate(node);
		}
	}
	// 平衡树，无需旋转，直接返回
	return node;
}

/*插入节点*/
void AVLTree::insert(int val){
	root = insertHelper(root, val);
}
/*递归插入节点（辅助方法）*/
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
		// 重复节点 直接返回
		return node;
	updateHeight(node); // 更新节点高度
	// 执行旋转操作，使该子树重新恢复平衡
	node = rotate(node);
	// 返回子树根节点
	return node;
}

/*删除节点*/
void AVLTree::remove(int val){
	root = removeHelper(root, val);
}
/*递归删除节点（辅助方法）*/
TreeNode *AVLTree::removeHelper(TreeNode *node, int val){
	if (node == nullptr){
		return nullptr;
	}
	/*查找节点并删除*/
	if (node->val < val){
		node->right = removeHelper(node->right, val);
	}
	else if (node->val > val){
		node->left = removeHelper(node->left, val);
	}
	else{
		// 子节点数量为0 或 1
		if (node->left == nullptr || node->right == nullptr){
			TreeNode *child = node->left == nullptr ? node->right : node->left;
			delete node;
			node = child;
		}
		// 子节点数量为 2
		else{
			// 找到中序遍历的后一个节点（右子树的最左边元素）
			TreeNode *tmp = node->right;
			while (tmp->left != nullptr){
				tmp = tmp->left;
			}
			int tmpVal = tmp->val;
			// 递归删除 (返回值是根节点)（删除右子树的最左边元素返回值就是右子树根节点）
			node->right = removeHelper(node->right, tmpVal);
			// 再覆盖值（相当于交换后删除）
			node->val = tmpVal;
		}
	}
	updateHeight(node); // 更新每次遇到的节点高度
	// 执行旋转操作，使该子树重新恢复平衡
	node = rotate(node);
	// 返回子树的根节点
	return node;
}