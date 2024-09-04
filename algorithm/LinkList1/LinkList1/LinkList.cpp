#include "iostream"
using namespace std;
/*链表节点结构体*/
struct ListNode{
	int val;  // 节点值
	ListNode* next;  // 指向下一节点的指针
	ListNode(int x) :val(x), next(nullptr){}  // 构造函数
};
/*打印链表*/
void printLinkList(ListNode *n0){
	cout << "[";
	while (n0 != nullptr){
		cout << n0->val << ((n0->next == nullptr) ? "" : ", ");
		n0 = n0->next;
	}
	cout << "]" << endl;

}
/*初始化链表*/
ListNode* linkListInit(){
	ListNode *n0 = new ListNode(1);
	ListNode *n1 = new ListNode(3);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(5);
	ListNode *n4 = new ListNode(4);
	// 构建节点之间的引用
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	return n0;
}
/*在链表pos位置处插入新节点*/
bool insertListNode(ListNode *pos,ListNode * newNode){
	newNode->next = pos->next;
	pos->next = newNode;
	return true;
}

/*删除链表中pos位置之后一个节点*/
bool deleteListNode(ListNode *pos){
	if (pos->next == nullptr)
		return false;
	// 要删除的节点
	ListNode *p = pos->next;
	pos->next = p->next;
	delete p;
	return true;
}
/*访问节点*/
ListNode * acess(ListNode* head, int index){
	if (head == nullptr || index < 0){
		return nullptr;
	}
	for (int i = 0; i < index; i++){
		if (head == nullptr)
			return nullptr;
		head = head->next;
	}
	return head;
}
/*查找节点 返回索引*/
int find(ListNode* head,int target){
	int index = 0;
	while (head != nullptr){
		if (target == head->val)
			return index;
		index++;
		head = head->next;
	}
	return -1;
}

/* 双向链表节点结构体 */
struct DListNode {
	int val; // 节点值
	DListNode *next; // 指向后继节点的指针
	DListNode *prev; // 指向前驱节点的指针
	DListNode(int x) : val(x), next(nullptr), prev(nullptr) {} // 构造函数
};

void testFunc(){
	ListNode * n0 = linkListInit();
	ListNode * ins = new ListNode(9);
	insertListNode(n0->next->next->next, ins);
	deleteListNode(n0->next->next->next);
	printLinkList(n0);
	cout << "链表第" << find(n0,(acess(n0, 3)->val)) + 1<< "个元素：" << acess(n0, 3)->val << endl;;
}

int main(){
	testFunc();
	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}