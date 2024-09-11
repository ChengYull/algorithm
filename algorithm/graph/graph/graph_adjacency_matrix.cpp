#include "iostream"
#include "vector"
using namespace std;
/*基于邻接矩阵实现的无向图类*/
class GraphAdjMat{
	vector<int> vertices;					// 顶点列表，元素代表顶点值，索引代表顶点索引
	vector<vector<int>> adjMat;		// 邻接矩阵，行列索引代表对应的顶点索引

public:
	/*构造方法*/
	GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges){
		// 添加顶点
		// 添加边
	}

	/*获取顶点数量*/
	int size(){
		return vertices.size();
	}
	/*添加顶点*/
	void addVertex(int val){
		int n = size();
		vertices.push_back(val);
		// 在邻接矩阵中添加一行0
		adjMat.push_back(vector<int>(n, 0));
		// 在邻接矩阵中添加一列0
		for (vector<int> &row : adjMat){
			row.push_back(0);
		}
	}
	/*删除顶点*/
	void removeVertex(int index){
		if (index >= size()){
			cout << "顶点不存在" << endl;
			return;
		}
		// 在顶点列表中删除索引为index的顶点
		vertices.erase(vertices.begin() + index);
		// 邻接矩阵中删除索引 index 的行
		adjMat.erase(adjMat.begin() + index);
		// 邻接矩阵中删除索引 index 的列
		for (vector<int> &row : adjMat){
			row.erase(row.begin() + index);
		}
	}
	/*添加边*/
	void addEdge(int i, int j){
		// 索引越界与相等处理
		if (i < 0 || j < 0 || i >= size() || j >= size() || i == j){
			cout << "顶点不存在" << endl;
			return;
		}
		adjMat[i][j] = 1;
		adjMat[j][i] = 1;
	}
	/*删除边*/
	void removeEdge(int i, int j){
		// 索引越界与相等处理
		if (i < 0 || j < 0 || i >= size() || j >= size() || i == j){
			cout << "顶点不存在" << endl;
			return;
		}
		adjMat[i][j] = 0;
		adjMat[j][i] = 0;
	}

};
vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex *startVet){

}