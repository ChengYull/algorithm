#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
/*顶点*/
class Vertex{
	int val;
};

/*基于邻接表实现的无向图类*/
class GraphAdjList{
public:
	// 邻接表； key:顶点，value：该顶点的所有邻接顶点
	unordered_map<Vertex*, vector<Vertex*>> adjList;

	/*构造方法*/
	GraphAdjList(const vector<vector<Vertex*>> &edges){
		// 添加所有顶点和边
		for (const vector<Vertex*> &edge : edges){
			addVertex(edge[0]);
			addVertex(edge[1]);
			addEdge(edge[0], edge[1]);
		}
	}

	/*在vector中删除指定节点*/
	void remove(vector<Vertex*> &vec, Vertex *vet){
		for (int i = 0; i < vec.size(); i++){
			if (vec[i] == vet){
				vec.erase(vec.begin() + i);
				break;
			}
		}
	}
	
	/*获取顶点数量*/
	int size(){
		return adjList.size();
	}
	/*添加边*/
	void addEdge(Vertex* vet1, Vertex* vet2){
		// 顶点不存在 或 两个顶点相同
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
			cout << "顶点不存在" << endl;
			return;
		}
		adjList[vet1].push_back(vet2);
		adjList[vet2].push_back(vet1);
	}
	/*删除边*/
	void removeEdge(Vertex* vet1, Vertex* vet2){
		// 顶点不存在 或 两个顶点相同
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
			cout << "顶点不存在" << endl;
			return;
		}
		remove(adjList[vet1], vet2);
		remove(adjList[vet2], vet1);
	}
	/*添加顶点*/
	void addVertex(Vertex* vet){
		if (adjList.count(vet)){
			cout << "顶点已存在" << endl;
			return;
		}
		// 在邻接表中添加一个新链表
		adjList[vet] = vector<Vertex*>();
	}
	/*删除顶点*/
	void removeVertex(Vertex *vet){
		// 顶点不存在 或 两个顶点相同
		if (!adjList.count(vet) ){
			cout << "顶点不存在" << endl;
			return;
		}
		// 在邻接表中删除顶点vet对应的链表
		adjList.erase(vet);
		// 遍历其他顶点的链表，删除所有包含 vet 的边
		for (auto &adj : adjList){
			remove(adj.second, vet);
		}
	}
};
