#include "queue"
#include "graph_adjacency_list.cpp"
#include "unordered_set"
using namespace std;

/*广度优先遍历*/
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex *startVet){
	// 顶点遍历序列
	vector<Vertex*> res;
	// 避免重复哈希表 用于记录访问过的顶点
	unordered_set<Vertex*> visited;
	// 队列
	queue<Vertex*> que;
	que.push(startVet);

	while (!que.empty()){
		Vertex* vet = que.front();
		que.pop();
		res.push_back(vet);
		for (Vertex* v : graph.adjList[vet]){
			if (!visited.count(vet)){
				que.push(v);			// 只入队为访问的顶点
				visited.emplace(v); // 标记该顶点已被访问
			}
		}
	}
	return res;
}