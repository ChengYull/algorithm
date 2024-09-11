#include "queue"
#include "graph_adjacency_list.cpp"
#include "unordered_set"
using namespace std;

/*������ȱ���*/
// ʹ���ڽӱ�����ʾͼ���Ա��ȡָ������������ڽӶ���
vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex *startVet){
	// �����������
	vector<Vertex*> res;
	// �����ظ���ϣ�� ���ڼ�¼���ʹ��Ķ���
	unordered_set<Vertex*> visited;
	// ����
	queue<Vertex*> que;
	que.push(startVet);

	while (!que.empty()){
		Vertex* vet = que.front();
		que.pop();
		res.push_back(vet);
		for (Vertex* v : graph.adjList[vet]){
			if (!visited.count(vet)){
				que.push(v);			// ֻ���Ϊ���ʵĶ���
				visited.emplace(v); // ��Ǹö����ѱ�����
			}
		}
	}
	return res;
}