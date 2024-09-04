#include "iostream"
#include "queue"
#include "vector"
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std;



/*�������*/
vector<int> levelOrder(TreeNode *root){
	// ��ʼ�����У�������ڵ�
	queue<TreeNode *> que;
	que.push(root);
	// ����һ��vector���ڴ�ӡ
	vector<int> vec;
	while (!que.empty()){
		TreeNode *node = que.front();
		que.pop(); // �ڵ����
		vec.push_back(node->val); // ����ڵ�ֵ
		if (node->left != nullptr){
			que.push(node->left);		//���ӽ�����
		}
		if (node->right != nullptr){
			que.push(node->right);		// ���ӽڵ���� 
		}
	}
	return vec;
}
/*ǰ�����*/
void preOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// �������ȼ������ڵ� -> ������ -> ������
	res.push_back(root->val);
	preOrder(root->left, res);
	preOrder(root->right, res);
}
/*�������*/
void inOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// �������ȼ��������� -> ���ڵ� -> ������
	inOrder(root->left, res);
	res.push_back(root->val);
	inOrder(root->right, res);
}
/*�������*/
void postOrder(TreeNode *root, vector<int> &res){
	if (root == nullptr){
		return;
	}
	// �������ȼ��� ������ -> ������ -> ���ڵ�
	postOrder(root->left, res);
	postOrder(root->right, res);
	res.push_back(root->val);
}
/*��ӡvector*/
void printVector(vector<int> vec){
	for (int n : vec){
		cout << n << " ";
	}
	cout << endl;
}
/*�����ʾ�µĶ�������*/
class ArrayBinaryTree{
public:
	/*���췽��*/
	ArrayBinaryTree(vector<int> arr){
		tree = arr;
	}
	/*�б�����*/
	int size(){
		return tree.size();
	}
	/*��ȡ����Ϊi�ڵ��ֵ*/
	int val(int i){
		// ������Խ�磬�򷵻� INT_MAX�������λ
		if (i < 0 || i >= size())
			return INT_MAX;
		return tree[i];
	}
	/*��ȡ����Ϊi�ڵ�����ӽ�������*/
	int left(int i){
		return 2 * i + 1;
	}
	/*��ȡ����Ϊi�ڵ�����ӽڵ������*/
	int right(int i){
		return 2 * i + 2;
	}
	/*��ȡ����Ϊi�ڵ�ĸ��ڵ������*/
	int parent(int i){
		return (i - 1) / 2;
	}
	/*�������*/
	vector<int> levelOrder(){
		vector<int> vec;
		for (int num : tree){
			if (num != INT_MAX)
				vec.push_back(num);
		}
		return vec;
	}
	/*ǰ�����*/
	vector<int> preOrder(){
		vector<int> vec;
		dfs(0, "pre", vec);
		return vec;
	}
	/*�������*/
	vector<int> inOrder(){
		vector<int> vec;
		dfs(0, "in", vec);
		return vec;
	}
	/*�������*/
	vector<int> postOrder(){
		vector<int> vec;
		dfs(0, "post", vec);
		return vec;
	}

private:
	vector<int> tree;
	/*������ȱ���*/
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

/*���ҽڵ�*/
TreeNode *search(int num,TreeNode *root){
	TreeNode * cur = root;
	while (cur != nullptr){
		// Ŀ��ڵ���cur��������
		if (cur->val > num){
			cur = cur->left;
		// Ŀ��ڵ���cur��������
		}else if (cur->val < num){
			cur = cur->right;
		}
		// �ҵ�Ŀ��ڵ㣬����ѭ��
		else{
			break;
		}
	}
	return cur;
}

void testTree(){
	/*��ʼ��������*/
	// ��ʼ���ڵ�
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

	// �����ڵ�֮������ã�ָ�룩
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	/*������ɾ���ڵ�*/
	TreeNode *P = new TreeNode(0);
	// �� n1 -> n2 ֮�����ڵ� P
	n1->left = P;
	P->left = n2;
	// ɾ�� P �ڵ�
	n1->left = n2;

	vector<int> op = levelOrder(n1);
	cout << "�������: " << endl;
	printVector(op);

	vector<int> pre_res;
	preOrder(n1, pre_res);
	cout << "ǰ�����: " << endl;
	printVector(pre_res);

	vector<int> in_res;
	inOrder(n1, in_res);
	cout << "�������: " << endl;
	printVector(in_res);

	vector<int> post_res;
	postOrder(n1, post_res);
	cout << "�������: " << endl;
	printVector(post_res);

	cout << "==========�����ʾ==========" << endl;

	/* �������������ʾ */
	// ʹ�� int ���ֵ INT_MAX ��ǿ�λ
	vector<int> tree = { 1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15 };
	ArrayBinaryTree *arrTree = new ArrayBinaryTree(tree);
	vector<int> level_order = arrTree->levelOrder();
	cout << "���������" << endl;
	printVector(level_order);
	vector<int> pre_order = arrTree->preOrder();
	cout << "ǰ�������" << endl;
	printVector(pre_order);
	vector<int> in_order = arrTree->inOrder();
	cout << "���������" << endl;
	printVector(in_order);
	vector<int> post_order = arrTree->postOrder();
	cout << "���������" << endl;
	printVector(post_order);

	cout << "==========����������==========" << endl;
	BinarySearchTree *searchTree = new BinarySearchTree();
	searchTree->insert(9);
	searchTree->insert(10);
	searchTree->insert(8);
	searchTree->insert(5);
	searchTree->insert(11);
	cout << "���� 11 ��" << searchTree->search(11)->val << endl;
	cout << "���������" << endl;
	vector<int> search_in;
	inOrder(searchTree->root, search_in);
	printVector(search_in);

	searchTree->remove(9);
	vector<int> search_in2;
	inOrder(searchTree->root, search_in2);
	printVector(search_in2);

	cout << "==========AVL������==========" << endl;
	AVLTree *avl_tree = new AVLTree();
	avl_tree->insert(9);
	avl_tree->insert(10);
	avl_tree->insert(8);
	avl_tree->insert(5);
	avl_tree->insert(11);
	cout << "���������" << endl;
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