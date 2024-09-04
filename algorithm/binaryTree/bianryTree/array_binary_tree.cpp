#include "iostream"
#include "vector"

using namespace std;
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
		return (i - 1)/ 2;
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