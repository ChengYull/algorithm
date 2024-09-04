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
	ListNode * stackTop; // 将头节点作为栈顶
	int stackSize;   // 栈长度
public:
	LinkedListStack(){
		stackTop = nullptr;
		stackSize = 0;
	}
	~LinkedListStack(){
		/*遍历链表每个节点 释放内存*/
		while (stackTop != nullptr){
			ListNode *tem = stackTop;
			stackTop = stackTop->next;
			delete tem;
		}
	}
	/*获取栈长度*/
	int size(){
		return stackSize;
	}

	/*判断栈是否为空*/
	bool isEmpty(){
		return (stackSize == 0);
	}

	/*入栈*/
	void push(int num){

		ListNode * node = new ListNode(num);
		node->next = stackTop;
		stackTop = node;
		stackSize++;
	}

	/*出栈*/
	int pop(){
		int num = top();
		ListNode * tem = stackTop;
		stackTop = stackTop->next;
		delete tem;
		stackSize--;
		return num;
	}

	/*访问栈顶元素*/
	int top(){
		if (isEmpty())
			throw out_of_range("栈为空");
		return stackTop->val;
	}
};

void testLinkedListStack(){
	/*初始化栈*/
	LinkedListStack sta;

	/*元素入栈*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*访问栈顶元素*/
	int top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*元素出栈*/
	sta.pop();
	cout << "元素出栈" << endl;
	top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*获取栈的长度*/
	int sta_size = sta.size();
	cout << "栈长度：" << sta_size << endl;

	/*判断是否为空*/
	bool sta_empty = sta.isEmpty();
	cout << "是否为空：" << sta_empty << endl;
}

class ArrayStack{
private:
	vector<int> sta;
public:
	/*获取栈长度*/
	int size(){
		return sta.size();
	}
	/*判断栈是否为空*/
	bool isEmpty(){
		return (size() == 0);
	}
	/*入栈*/
	void push(int num){
		sta.push_back(num);
	}
	/*出栈*/
	int pop(){
		int num = top();
		sta.pop_back();
		return num;
	}
	/*访问栈顶元素*/
	int top(){
		if (isEmpty())
			throw out_of_range("栈为空");
		return sta[size()-1];
	}
};

void testArrayStack(){
	/*初始化栈*/
	ArrayStack sta;

	/*元素入栈*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*访问栈顶元素*/
	int top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*元素出栈*/
	sta.pop();
	cout << "元素出栈" << endl;
	top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*获取栈的长度*/
	int sta_size = sta.size();
	cout << "栈长度：" << sta_size << endl;

	/*判断是否为空*/
	bool sta_empty = sta.isEmpty();
	cout << "是否为空：" << sta_empty << endl;
}

void test(){
	/*初始化栈*/
	stack<int> sta;

	/*元素入栈*/
	sta.push(1);
	sta.push(3);
	sta.push(2);
	sta.push(5);
	sta.push(4);

	/*访问栈顶元素*/
	int top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*元素出栈*/
	sta.pop();
	cout << "元素出栈" << endl;
	top = sta.top();
	cout << "栈顶元素：" << top << endl;

	/*获取栈的长度*/
	int sta_size = sta.size();
	cout << "栈长度：" << sta_size << endl;

	/*判断是否为空*/
	bool sta_empty = sta.empty();
	cout << "是否为空：" << sta_empty << endl;
	
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