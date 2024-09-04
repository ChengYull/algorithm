#include "iostream"
#include "stack"
#include "list"
#include "vector"
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
	ListNode(int x,ListNode *next) :val(x), next(next){}
};

class LinkedListStack{
private:
	ListNode * stackTop; // ��ͷ�ڵ���Ϊջ��
	int stackSize;   // ջ����
public:
	LinkedListStack(){
		stackTop = nullptr;
		stackSize = 0;
	}
	~LinkedListStack(){
		/*��������ÿ���ڵ� �ͷ��ڴ�*/
		while (stackTop != nullptr){
			ListNode *tem = stackTop;
			stackTop = stackTop->next;
			delete tem;
		}
	}
	/*��ȡջ����*/
	int size(){
		return stackSize;
	}

	/*�ж�ջ�Ƿ�Ϊ��*/
	bool isEmpty(){
		return (stackSize == 0);
	}

	/*��ջ*/
	void push(int num){

		ListNode * node = new ListNode(num);
		node->next = stackTop;
		stackTop = node;
		stackSize++;
	}

	/*��ջ*/
	int pop(){
		int num = top();
		ListNode * tem = stackTop;
		stackTop = stackTop->next;
		delete tem;
		stackSize--;
		return num;
	}

	/*����ջ��Ԫ��*/
	int top(){
		if (isEmpty())
			throw out_of_range("ջΪ��");
		return stackTop->val;
	}
};

void testLinkedListStack(){
	/*��ʼ��ջ*/
	LinkedListStack sta;

	/*Ԫ����ջ*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*����ջ��Ԫ��*/
	int top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*Ԫ�س�ջ*/
	sta.pop();
	cout << "Ԫ�س�ջ" << endl;
	top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*��ȡջ�ĳ���*/
	int sta_size = sta.size();
	cout << "ջ���ȣ�" << sta_size << endl;

	/*�ж��Ƿ�Ϊ��*/
	bool sta_empty = sta.isEmpty();
	cout << "�Ƿ�Ϊ�գ�" << sta_empty << endl;
}

class ArrayStack{
private:
	vector<int> sta;
public:
	/*��ȡջ����*/
	int size(){
		return sta.size();
	}
	/*�ж�ջ�Ƿ�Ϊ��*/
	bool isEmpty(){
		return (size() == 0);
	}
	/*��ջ*/
	void push(int num){
		sta.push_back(num);
	}
	/*��ջ*/
	int pop(){
		int num = top();
		sta.pop_back();
		return num;
	}
	/*����ջ��Ԫ��*/
	int top(){
		if (isEmpty())
			throw out_of_range("ջΪ��");
		return sta[size()-1];
	}
};

void testArrayStack(){
	/*��ʼ��ջ*/
	ArrayStack sta;

	/*Ԫ����ջ*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*����ջ��Ԫ��*/
	int top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*Ԫ�س�ջ*/
	sta.pop();
	cout << "Ԫ�س�ջ" << endl;
	top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*��ȡջ�ĳ���*/
	int sta_size = sta.size();
	cout << "ջ���ȣ�" << sta_size << endl;

	/*�ж��Ƿ�Ϊ��*/
	bool sta_empty = sta.isEmpty();
	cout << "�Ƿ�Ϊ�գ�" << sta_empty << endl;
}

void test(){
	/*��ʼ��ջ*/
	stack<int> sta;

	/*Ԫ����ջ*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*����ջ��Ԫ��*/
	int top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*Ԫ�س�ջ*/
	sta.pop();
	cout << "Ԫ�س�ջ" << endl;
	top = sta.top();
	cout << "ջ��Ԫ�أ�" << top << endl;

	/*��ȡջ�ĳ���*/
	int sta_size = sta.size();
	cout << "ջ���ȣ�" << sta_size << endl;

	/*�ж��Ƿ�Ϊ��*/
	bool sta_empty = sta.empty();
	cout << "�Ƿ�Ϊ�գ�" << sta_empty << endl;
	
}

int main(){
	test();
	cout << "--------------------------"<< endl;
	testLinkedListStack();
	cout << "--------------------------" << endl;
	testArrayStack();
	system("pause");
	return 0;
}