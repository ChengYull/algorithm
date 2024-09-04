#include "iostream"
#include "vector"

using namespace std;
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
		return (i - 1)/ 2;
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