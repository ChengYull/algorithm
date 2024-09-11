#include "graph_adjacency_list.cpp"
#include "unordered_set"


/*������ȱ�����������*/
void dfs(GraphAdjList &graph, unordered_set<Vertex*> &visited, vector<Vertex*> &res, Vertex * vet){
	res.push_back(vet);		// ��¼���ʶ���
	visited.emplace(vet);		// ��Ǹö����ѱ�����
	
	// �����ö���������ڽӶ���
	for (Vertex* adjVet : graph.adjList[vet]){
		if (visited.count(adjVet))
			continue; // �����ѱ����ʵĶ���
		// �ݹ�����ڽӶ���
		dfs(graph, visited, res, adjVet);
	}
}
/*������ȱ���*/
// ʹ���ڽӱ�����ʾͼ���Ա��ȡָ��������ڽӶ���
vector<Vertex*> graphDFS(GraphAdjList &graph, Vertex* startVet){
	// �����������
	vector<Vertex*> res;
	// ��ϣ�����ڼ�¼�����ʹ��Ķ���
	unordered_set<Vertex*> visted;
	dfs(graph, visted, res, startVet);
	return res;
}