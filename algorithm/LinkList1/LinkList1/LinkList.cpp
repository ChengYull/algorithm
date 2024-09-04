#include "iostream"
using namespace std;
/*����ڵ�ṹ��*/
struct ListNode{
	int val;  // �ڵ�ֵ
	ListNode* next;  // ָ����һ�ڵ��ָ��
	ListNode(int x) :val(x), next(nullptr){}  // ���캯��
};
/*��ӡ����*/
void printLinkList(ListNode *n0){
	cout << "[";
	while (n0 != nullptr){
		cout << n0->val << ((n0->next == nullptr) ? "" : ", ");
		n0 = n0->next;
	}
	cout << "]" << endl;

}
/*��ʼ������*/
ListNode* linkListInit(){
	ListNode *n0 = new ListNode(1);
	ListNode *n1 = new ListNode(3);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(5);
	ListNode *n4 = new ListNode(4);
	// �����ڵ�֮�������
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	return n0;
}
/*������posλ�ô������½ڵ�*/
bool insertListNode(ListNode *pos,ListNode * newNode){
	newNode->next = pos->next;
	pos->next = newNode;
	return true;
}

/*ɾ��������posλ��֮��һ���ڵ�*/
bool deleteListNode(ListNode *pos){
	if (pos->next == nullptr)
		return false;
	// Ҫɾ���Ľڵ�
	ListNode *p = pos->next;
	pos->next = p->next;
	delete p;
	return true;
}
/*���ʽڵ�*/
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
/*���ҽڵ� ��������*/
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

/* ˫������ڵ�ṹ�� */
struct DListNode {
	int val; // �ڵ�ֵ
	DListNode *next; // ָ���̽ڵ��ָ��
	DListNode *prev; // ָ��ǰ���ڵ��ָ��
	DListNode(int x) : val(x), next(nullptr), prev(nullptr) {} // ���캯��
};

void testFunc(){
	ListNode * n0 = linkListInit();
	ListNode * ins = new ListNode(9);
	insertListNode(n0->next->next->next, ins);
	deleteListNode(n0->next->next->next);
	printLinkList(n0);
	cout << "�����" << find(n0,(acess(n0, 3)->val)) + 1<< "��Ԫ�أ�" << acess(n0, 3)->val << endl;;
}

int main(){
	testFunc();
	cout << "Hello World!" << endl;
	system("pause");
	return 0;
}