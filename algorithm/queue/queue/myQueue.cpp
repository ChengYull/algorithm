#include "iostream"
#include "queue"
#include "deque"
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

class LinkedListQueue{
private:
	ListNode *front; // 头节点
	ListNode *rear; // 尾节点
	int queSize;  // 队列长度
public:
	LinkedListQueue(){
		front = nullptr;
		rear = nullptr;
		queSize = 0;
	}
	~LinkedListQueue(){
		while (front != nullptr){
			ListNode *tmp = front;
			front = front->next;
			delete tmp;
		}
	}
	/*获取队列长度*/
	int size(){
		return queSize;
	}
	/*判断队列是否为空*/
	bool isEmpty(){
		return (size() == 0);
	}
	/*入队*/
	void push(int num){
		ListNode *node = new ListNode(num);
		if (isEmpty()){
			front = node;
			rear = node;
		}else{
			rear->next = node;
			rear = node;
		}
		queSize++;
	}
	/*出队*/
	int pop(){
		int num = peek();
		ListNode *tmp = front;
		front = front->next;
		delete tmp;
		queSize--;
		return num;
	}
	/*访问队首元素*/
	int peek(){
		if (isEmpty())
			throw out_of_range("队列为空");
		return front->val;
	}
};

void testLinkedListQueue(){
	/*初始化队列*/
	LinkedListQueue que;

	/*元素入队*/
	que.push(1);
	que.push(3);
	que.push(2);
	que.push(5);
	que.push(4);

	/*访问队首元素*/
	int que_front = que.peek();
	cout << "队首元素：" << que_front << endl;

	/*元素出队*/
	cout << "元素出队" << endl;
	que.pop();
	cout << "队首元素：" << que.peek() << endl;
	/*获取队列的长度*/
	int que_size = que.size();
	cout << "队列长度：" << que_size << endl;
	/*判断队列是否为空*/
	bool que_empty = que.isEmpty();
	cout << "队列是否为空：" << que_empty << endl;
}

/*基于环形数组实现的队列*/
class ArrayQueue{
private:
	int * nums; // 用于存储队列元素的数组
	int front;   // 队首指针 ，指向队首元素
	int queSize; // 队列长度
	int queCapacity; // 队列容量
public:
	ArrayQueue(int capacity){
		nums = new int[capacity];
		queCapacity = capacity;
		front = 0;
		queSize = 0;
	}
	~ArrayQueue()	{
		delete nums;
	}
	/*获取队列的容量*/
	int capacity(){
		return queCapacity;
	}
	/*获取队列长度*/
	int size(){
		return queSize;
	}
	/*判断队列是否为空*/
	bool isEmpty(){
		return (queSize == 0);
	}
	/*入队*/
	void push(int num){
		if (queSize == queCapacity){
			cout << "队列已满" << endl;
			return;
		}
		// 通过取余操作实现 rear 越过数组尾部后回到头部
		int rear = (front + queSize) % queCapacity;
		nums[rear] = num;
		queSize++;
	}
	/*出队*/
	int pop(){
		int num = peek();
		// 队首指针向后移动一位，若越过尾部，则返回到数组头部
		front = (front + 1) % queCapacity;
		queSize--;
		return num;
	}
	/*访问队首元素*/
	int peek(){
		if (isEmpty())
			throw out_of_range("队列为空");
		return nums[front];
	}

};

void testArrayQueue(){
	/*初始化队列*/
	ArrayQueue *que = new ArrayQueue(5);

	/*元素入队*/
	que->push(1);
	que->push(3);
	que->push(2);
	que->push(5);
	que->push(4);

	/*访问队首元素*/
	int que_front = que->peek();
	cout << "队首元素：" << que_front << endl;

	/*元素出队*/
	cout << "元素出队" << endl;
	que->pop();
	cout << "队首元素：" << que->peek() << endl;
	/*获取队列的长度*/
	int que_size = que->size();
	cout << "队列长度：" << que_size << endl;
	/*判断队列是否为空*/
	bool que_empty = que->isEmpty();
	cout << "队列是否为空：" << que_empty << endl;

	cout << que->pop() << endl;
	cout << que->pop() << endl;
	cout << que->pop() << endl;
	cout << que->pop() << endl;

}

void testQueue(){
	/*初始化队列*/
	queue<int> que;

	/*元素入队*/
	que.push(1);
	que.push(3);
	que.push(2);
	que.push(5);
	que.push(4);

	/*访问队首元素*/
	int que_front = que.front();
	cout << "队首元素：" << que_front << endl;

	/*元素出队*/
	cout << "元素出队" << endl;
	que.pop();
	cout << "队首元素：" << que.front() << endl;
	/*获取队列的长度*/
	int que_size = que.size();
	cout << "队列长度：" << que_size << endl;
	/*判断队列是否为空*/
	bool que_empty = que.empty();
	cout << "队列是否为空：" << que_empty << endl;
}

void testDeuqe(){
	deque<int> que;
	/*元素入队*/
	que.push_back(2);
	que.push_back(5);
	que.push_back(4);
	que.push_front(3);
	que.push_front(1);

	/*访问元素*/
	int front = que.front();  // 队首元素
	int back = que.back();  // 队尾元素
	cout << "队首元素：" << front << endl;
	cout << "队尾元素：" << back << endl;

	/*元素出队*/
	que.pop_front();  //队首元素出队
	cout << "队首元素出队" << endl;
	que.pop_back();  // 队尾元素出队
	cout << "队尾元素出队" << endl;
	cout << "队首元素：" << que.front() << endl;
	cout << "队尾元素：" << que.back() << endl;

	/*获取双向队列的长度*/
	int size = que.size();
	cout << "队列长度：" << size << endl;
	/*判断双向队列是否为空*/
	bool empty = que.empty();
	cout << "是否为空 ： " << empty << endl;

}

int main(){
	cout << "-------------队列-------------" << endl;
	testQueue();
	cout << "-------------链表-------------" << endl;
	testLinkedListQueue();
	cout << "-------------数组-------------" << endl;
	testArrayQueue();
	cout << "-----------双向队列-----------" << endl;
	testDeuqe();
	system("pause");
	return 0;
}