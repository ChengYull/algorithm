#include "iostream"
#include "queue"
#include "vector"
#include <functional>
#include "my_heap.cpp"
using namespace std;

void testHeap(){
	/*��ʼ����*/
	// ��ʼ��С����
	//priority_queue<int, vector<int>, greater<int>> minHeap;
	// ��ʼ���󶥶�
	priority_queue<int, vector<int>, less<int>> maxHeap;

	/*Ԫ�����*/
	maxHeap.push(1);
	maxHeap.push(3);
	maxHeap.push(2);
	maxHeap.push(5);
	maxHeap.push(4);

	/*��ȡ�Ѷ�Ԫ��*/
	int peek = maxHeap.top(); // 5
	cout << peek << endl;

	/*�Ѷ�Ԫ�س���*/
	// ����Ԫ�ػ��γ�һ���Ӵ�С������
	maxHeap.pop(); // 5
	maxHeap.pop(); // 4
	maxHeap.pop(); // 3
	maxHeap.pop(); // 2
	maxHeap.pop(); // 1

	/*��ȡ�Ѵ�С*/
	int size = maxHeap.size();
	cout << size << endl;

	/*�ж϶��Ƿ�Ϊ��*/
	bool isEmpty = maxHeap.empty();
	cout << isEmpty << endl;

	/*�����б�����*/
	vector<int> input{ 1, 3, 2, 5, 4 };
	priority_queue<int, vector<int>, greater<int>> minHeap(input.begin(), input.end());
	cout << minHeap.top() << endl;
}

int main(){
	cout << "heap.cpp" << endl;
	MaxHeap *mh = new MaxHeap;
	mh->push(1);
	mh->push(3);
	mh->push(2);
	mh->push(5);
	mh->push(4);
	
	cout << mh->peak() << endl;
	mh->pop();
	cout << mh->peak() << endl;
	mh->pop();
	cout << mh->peak() << endl;
	mh->pop();
	cout << mh->peak() << endl;
	mh->pop();
	cout << mh->peak() << endl;

	system("pause");
	return 0;
}