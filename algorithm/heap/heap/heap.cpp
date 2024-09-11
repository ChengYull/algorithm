#include "iostream"
#include "queue"
#include "vector"
#include <functional>
#include "my_heap.cpp"
using namespace std;

void testHeap(){
	/*初始化堆*/
	// 初始化小顶堆
	//priority_queue<int, vector<int>, greater<int>> minHeap;
	// 初始化大顶堆
	priority_queue<int, vector<int>, less<int>> maxHeap;

	/*元素入堆*/
	maxHeap.push(1);
	maxHeap.push(3);
	maxHeap.push(2);
	maxHeap.push(5);
	maxHeap.push(4);

	/*获取堆顶元素*/
	int peek = maxHeap.top(); // 5
	cout << peek << endl;

	/*堆顶元素出堆*/
	// 出堆元素会形成一个从大到小的序列
	maxHeap.pop(); // 5
	maxHeap.pop(); // 4
	maxHeap.pop(); // 3
	maxHeap.pop(); // 2
	maxHeap.pop(); // 1

	/*获取堆大小*/
	int size = maxHeap.size();
	cout << size << endl;

	/*判断堆是否为空*/
	bool isEmpty = maxHeap.empty();
	cout << isEmpty << endl;

	/*输入列表并建堆*/
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