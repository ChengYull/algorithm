#include "iostream"
#include "vector"
using namespace std;
/*�����ڽӾ���ʵ�ֵ�����ͼ��*/
class GraphAdjMat{
	vector<int> vertices;					// �����б�Ԫ�ش�����ֵ����������������
	vector<vector<int>> adjMat;		// �ڽӾ����������������Ӧ�Ķ�������

public:
	/*���췽��*/
	GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges){
		// ��Ӷ���
		// ��ӱ�
	}

	/*��ȡ��������*/
	int size(){
		return vertices.size();
	}
	/*��Ӷ���*/
	void addVertex(int val){
		int n = size();
		vertices.push_back(val);
		// ���ڽӾ��������һ��0
		adjMat.push_back(vector<int>(n, 0));
		// ���ڽӾ��������һ��0
		for (vector<int> &row : adjMat){
			row.push_back(0);
		}
	}
	/*ɾ������*/
	void removeVertex(int index){
		if (index >= size()){
			cout << "���㲻����" << endl;
			return;
		}
		// �ڶ����б���ɾ������Ϊindex�Ķ���
		vertices.erase(vertices.begin() + index);
		// �ڽӾ�����ɾ������ index ����
		adjMat.erase(adjMat.begin() + index);
		// �ڽӾ�����ɾ������ index ����
		for (vector<int> &row : adjMat){
			row.erase(row.begin() + index);
		}
	}
	/*��ӱ�*/
	void addEdge(int i, int j){
		// ����Խ������ȴ���
		if (i < 0 || j < 0 || i >= size() || j >= size() || i == j){
			cout << "���㲻����" << endl;
			return;
		}
		adjMat[i][j] = 1;
		adjMat[j][i] = 1;
	}
	/*ɾ����*/
	void removeEdge(int i, int j){
		// ����Խ������ȴ���
		if (i < 0 || j < 0 || i >= size() || j >= size() || i == j){
			cout << "���㲻����" << endl;
			return;
		}
		adjMat[i][j] = 0;
		adjMat[j][i] = 0;
	}

};
vector<Vertex*> graphBFS(GraphAdjList &graph, Vertex *startVet){

}