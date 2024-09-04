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
	ListNode *front; // ͷ�ڵ�
	ListNode *rear; // β�ڵ�
	int queSize;  // ���г���
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
	/*��ȡ���г���*/
	int size(){
		return queSize;
	}
	/*�ж϶����Ƿ�Ϊ��*/
	bool isEmpty(){
		return (size() == 0);
	}
	/*���*/
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
	/*����*/
	int pop(){
		int num = peek();
		ListNode *tmp = front;
		front = front->next;
		delete tmp;
		queSize--;
		return num;
	}
	/*���ʶ���Ԫ��*/
	int peek(){
		if (isEmpty())
			throw out_of_range("����Ϊ��");
		return front->val;
	}
};

void testLinkedListQueue(){
	/*��ʼ������*/
	LinkedListQueue que;

	/*Ԫ�����*/
	que.push(1);
	que.push(3);
	que.push(2);
	que.push(5);
	que.push(4);

	/*���ʶ���Ԫ��*/
	int que_front = que.peek();
	cout << "����Ԫ�أ�" << que_front << endl;

	/*Ԫ�س���*/
	cout << "Ԫ�س���" << endl;
	que.pop();
	cout << "����Ԫ�أ�" << que.peek() << endl;
	/*��ȡ���еĳ���*/
	int que_size = que.size();
	cout << "���г��ȣ�" << que_size << endl;
	/*�ж϶����Ƿ�Ϊ��*/
	bool que_empty = que.isEmpty();
	cout << "�����Ƿ�Ϊ�գ�" << que_empty << endl;
}

/*���ڻ�������ʵ�ֵĶ���*/
class ArrayQueue{
private:
	int * nums; // ���ڴ洢����Ԫ�ص�����
	int front;   // ����ָ�� ��ָ�����Ԫ��
	int queSize; // ���г���
	int queCapacity; // ��������
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
	/*��ȡ���е�����*/
	int capacity(){
		return queCapacity;
	}
	/*��ȡ���г���*/
	int size(){
		return queSize;
	}
	/*�ж϶����Ƿ�Ϊ��*/
	bool isEmpty(){
		return (queSize == 0);
	}
	/*���*/
	void push(int num){
		if (queSize == queCapacity){
			cout << "��������" << endl;
			return;
		}
		// ͨ��ȡ�����ʵ�� rear Խ������β����ص�ͷ��
		int rear = (front + queSize) % queCapacity;
		nums[rear] = num;
		queSize++;
	}
	/*����*/
	int pop(){
		int num = peek();
		// ����ָ������ƶ�һλ����Խ��β�����򷵻ص�����ͷ��
		front = (front + 1) % queCapacity;
		queSize--;
		return num;
	}
	/*���ʶ���Ԫ��*/
	int peek(){
		if (isEmpty())
			throw out_of_range("����Ϊ��");
		return nums[front];
	}

};

void testArrayQueue(){
	/*��ʼ������*/
	ArrayQueue *que = new ArrayQueue(5);

	/*Ԫ�����*/
	que->push(1);
	que->push(3);
	que->push(2);
	que->push(5);
	que->push(4);

	/*���ʶ���Ԫ��*/
	int que_front = que->peek();
	cout << "����Ԫ�أ�" << que_front << endl;

	/*Ԫ�س���*/
	cout << "Ԫ�س���" << endl;
	que->pop();
	cout << "����Ԫ�أ�" << que->peek() << endl;
	/*��ȡ���еĳ���*/
	int que_size = que->size();
	cout << "���г��ȣ�" << que_size << endl;
	/*�ж϶����Ƿ�Ϊ��*/
	bool que_empty = que->isEmpty();
	cout << "�����Ƿ�Ϊ�գ�" << que_empty << endl;

	cout << que->pop() << endl;
	cout << que->pop() << endl;
	cout << que->pop() << endl;
	cout << que->pop() << endl;

}

void testQueue(){
	/*��ʼ������*/
	queue<int> que;

	/*Ԫ�����*/
	que.push(1);
	que.push(3);
	que.push(2);
	que.push(5);
	que.push(4);

	/*���ʶ���Ԫ��*/
	int que_front = que.front();
	cout << "����Ԫ�أ�" << que_front << endl;

	/*Ԫ�س���*/
	cout << "Ԫ�س���" << endl;
	que.pop();
	cout << "����Ԫ�أ�" << que.front() << endl;
	/*��ȡ���еĳ���*/
	int que_size = que.size();
	cout << "���г��ȣ�" << que_size << endl;
	/*�ж϶����Ƿ�Ϊ��*/
	bool que_empty = que.empty();
	cout << "�����Ƿ�Ϊ�գ�" << que_empty << endl;
}

void testDeuqe(){
	deque<int> que;
	/*Ԫ�����*/
	que.push_back(2);
	que.push_back(5);
	que.push_back(4);
	que.push_front(3);
	que.push_front(1);

	/*����Ԫ��*/
	int front = que.front();  // ����Ԫ��
	int back = que.back();  // ��βԪ��
	cout << "����Ԫ�أ�" << front << endl;
	cout << "��βԪ�أ�" << back << endl;

	/*Ԫ�س���*/
	que.pop_front();  //����Ԫ�س���
	cout << "����Ԫ�س���" << endl;
	que.pop_back();  // ��βԪ�س���
	cout << "��βԪ�س���" << endl;
	cout << "����Ԫ�أ�" << que.front() << endl;
	cout << "��βԪ�أ�" << que.back() << endl;

	/*��ȡ˫����еĳ���*/
	int size = que.size();
	cout << "���г��ȣ�" << size << endl;
	/*�ж�˫������Ƿ�Ϊ��*/
	bool empty = que.empty();
	cout << "�Ƿ�Ϊ�� �� " << empty << endl;

}

int main(){
	cout << "-------------����-------------" << endl;
	testQueue();
	cout << "-------------����-------------" << endl;
	testLinkedListQueue();
	cout << "-------------����-------------" << endl;
	testArrayQueue();
	cout << "-----------˫�����-----------" << endl;
	testDeuqe();
	system("pause");
	return 0;
}