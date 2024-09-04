#include "iostream"
#include "queue"
#include "vector"
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std;



/*层序遍历*/
vector<int> levelOrder(TreeNode *root){
	// 初始化队列，加入根节点
	queue<TreeNode *> que;
	que.push(root);
	// 返回一个vector用于打印
	vector<int> vec;
	while (!que.empty()){
		TreeNode *node = que.front();
		que.pop(); // 节点出队
		vec.push_back(node->val); // 保存节点值
		if (node->left != nullptr){
			que.push(node->left);		//左子结点入队
		}
		if (node->right != nullptr){
			que.push(node->right);		// 右子节点入队 
		}
	}
	return vec;
}
/*前序遍历*/
void preOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// 访问优先级：根节点 -> 左子树 -> 右子树
	res.push_back(root->val);
	preOrder(root->left, res);
	preOrder(root->right, res);
}
/*中序遍历*/
void inOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// 访问优先级：左子树 -> 根节点 -> 右子树
	inOrder(root->left, res);
	res.push_back(root->val);
	inOrder(root->right, res);
}
/*后序遍历*/
void postOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// 访问优先级： 左子树 -> 右子树 -> 根节点
	postOrder(root->left, res);
	postOrder(root->right, res);
	res.push_back(root->val);
}
/*打印vector*/
void printVector(vector<int> vec){
	for (int n : vec){
		cout << n << " ";
	}
	cout << endl;
}
/*数组表示下的二叉树类*/
class ArrayBinaryTree{
public:
	/*构造方法*/
	ArrayBinaryTree(vector<int> arr){
		tree = arr;
	}
	/*列表容量*/
	int size(){
		return tree.size();
	}
	/*获取索引为i节点的值*/
	int val(int i){
		// 若索引越界，则返回 INT_MAX，代表空位
		if (i < 0 || i >= size())
			return INT_MAX;
		return tree[i];
	}
	/*获取索引为i节点的左子结点的索引*/
	int left(int i){
		return 2 * i + 1;
	}
	/*获取索引为i节点的右子节点的索引*/
	int right(int i){
		return 2 * i + 2;
	}
	/*获取索引为i节点的父节点的索引*/
	int parent(int i){
		return (i - 1) / 2;
	}
	/*层序遍历*/
	vector<int> levelOrder(){
		vector<int> vec;
		for (int num : tree){
			if (num != INT_MAX)
				vec.push_back(num);
		}
		return vec;
	}
	/*前序遍历*/
	vector<int> preOrder(){
		vector<int> vec;
		dfs(0, "pre", vec);
		return vec;
	}
	/*中序遍历*/
	vector<int> inOrder(){
		vector<int> vec;
		dfs(0, "in", vec);
		return vec;
	}
	/*后序遍历*/
	vector<int> postOrder(){
		vector<int> vec;
		dfs(0, "post", vec);
		return vec;
	}

private:
	vector<int> tree;
	/*深度优先遍历*/
	void dfs(int i, string order, vector<int> &res){
		if (val(i) == INT_MAX){
			return;
		}
		if (order == "pre"){
			res.push_back(val(i));
		}
		dfs(left(i), order, res);
		if (order == "in"){
			res.push_back(val(i));
		}
		dfs(right(i), order, res);
		if (order == "post"){
			res.push_back(val(i));
		}
	}
};

/*查找节点*/
TreeNode *search(int num,TreeNode *root){
	TreeNode * cur = root;
	while (cur != nullptr){
		// 目标节点在cur左子树中
		if (cur->val > num){
			cur = cur->left;
		// 目标节点在cur右子树中
		}else if (cur->val < num){
			cur = cur->right;
		}
		// 找到目标节点，跳出循环
		else{
			break;
		}
	}
	return cur;
}

void testTree(){
	/*初始化二叉树*/
	// 初始化节点
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

	// 构建节点之间的引用（指针）
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	/*插入与删除节点*/
	TreeNode *P = new TreeNode(0);
	// 在 n1 -> n2 之间插入节点 P
	n1->left = P;
	P->left = n2;
	// 删除 P 节点
	n1->left = n2;

	vector<int> op = levelOrder(n1);
	cout << "层序遍历: " << endl;
	printVector(op);

	vector<int> pre_res;
	preOrder(n1, pre_res);
	cout << "前序遍历: " << endl;
	printVector(pre_res);

	vector<int> in_res;
	inOrder(n1, in_res);
	cout << "中序遍历: " << endl;
	printVector(in_res);

	vector<int> post_res;
	postOrder(n1, post_res);
	cout << "后序遍历: " << endl;
	printVector(post_res);

	cout << "==========数组表示==========" << endl;

	/* 二叉树的数组表示 */
	// 使用 int 最大值 INT_MAX 标记空位
	vector<int> tree = { 1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15 };
	ArrayBinaryTree *arrTree = new ArrayBinaryTree(tree);
	vector<int> level_order = arrTree->levelOrder();
	cout << "层序遍历：" << endl;
	printVector(level_order);
	vector<int> pre_order = arrTree->preOrder();
	cout << "前序遍历：" << endl;
	printVector(pre_order);
	vector<int> in_order = arrTree->inOrder();
	cout << "中序遍历：" << endl;
	printVector(in_order);
	vector<int> post_order = arrTree->postOrder();
	cout << "后序遍历：" << endl;
	printVector(post_order);

	cout << "==========二叉搜索树==========" << endl;
	BinarySearchTree *searchTree = new BinarySearchTree();
	searchTree->insert(9);
	searchTree->insert(10);
	searchTree->insert(8);
	searchTree->insert(5);
	searchTree->insert(11);
	cout << "查找 11 ：" << searchTree->search(11)->val << endl;
	cout << "中序遍历：" << endl;
	vector<int> search_in;
	inOrder(searchTree->root, search_in);
	printVector(search_in);

	searchTree->remove(9);
	vector<int> search_in2;
	inOrder(searchTree->root, search_in2);
	printVector(search_in2);

	cout << "==========AVL二叉树==========" << endl;
	AVLTree *avl_tree = new AVLTree();
	avl_tree->insert(9);
	avl_tree->insert(10);
	avl_tree->insert(8);
	avl_tree->insert(5);
	avl_tree->insert(11);
	cout << "中序遍历：" << endl;
	vector<int> vec_avl;
	inOrder(avl_tree->root, vec_avl);
	printVector(vec_avl);
	avl_tree->remove(8);
	vector<int> avl_vec;
	inOrder(avl_tree->root, avl_vec);
	printVector(avl_vec);
}



int main(){
	
	testTree();

	system("pause");
	return 0;
}