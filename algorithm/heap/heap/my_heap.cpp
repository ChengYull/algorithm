#include  "vector"
#include "iostream"
using namespace std;
class MaxHeap{
public:
	vector<int> maxHeap;

	MaxHeap(){}

	/*���췽�� �� ���������б���*/
	MaxHeap(vector<int> nums){
		// ���б�Ԫ��ԭ�ⲻ������ӽ���
		maxHeap = nums;
		// �ѻ���Ҷ�ڵ�������нڵ�
		for (int i = size() - 1; i >= 0; i--){
			siftDown(i);
		}
	}

	/*��ȡ���ӽڵ������*/
	int left(int i){
		return 2 * i + 1;
	}
	/*��ȡ���ӽڵ������*/
	int right(int i){
		return 2 * i + 2;
	}
	/*��ȡ���ڵ������*/
	int parent(int i){
		return (i - 1) / 2; // ��������
	}
	/*���ʶѶ�Ԫ��*/
	int peak(){
		return maxHeap[0];
	}

	/*��ȡ�ѳ���*/
	int size(){
		return maxHeap.size();
	}

	/*�ж��Ƿ�Ϊ��*/
	bool isEmpty(){
		return size() == 0;
	}

	/*Ԫ�����*/
	void push(int val){
		// ��ӽڵ�
		maxHeap.push_back(val);
		// �ӵ������ѻ�
		siftUp(size() - 1);
	}

	/*�ӵ������ѻ�*/
	void siftUp(int i){
		
		while (true){
			// ��ȡ�ڵ�i���ڵ�
			int p = parent(i);
			// ��Խ�����ڵ� �� �ڵ������޸�ʱ �����ѻ�
			if (p < 0 || maxHeap[i] < maxHeap[p]){
				break;
			}
			// �������ڵ�
			swap(maxHeap[i], maxHeap[p]);
			// ѭ�����϶ѻ�
			i = p;
		}
	}
	/*Ԫ�س���*/
	void pop(){
		// �пմ���
		if (isEmpty()){
			cout << "��Ϊ��" << endl;
			return;
		}
		// �����Ѷ��Ͷѵ����Ҷ˵�Ԫ��
		swap(maxHeap[0], maxHeap[size() - 1]);
		// �Ƴ��ѵ����Ҷ˵�Ԫ��
		maxHeap.pop_back();
		/*�Ӷ����׶ѻ�*/
		siftDown(0);
	}

	/*�Ӷ����׶ѻ�*/
	void siftDown(int i){
		while (true){
			// �ж� i,l,r ��ֵ���Ľڵ㣬��Ϊ ma
			int l = left(i), r = right(i), ma = i;
			if (l < size() && maxHeap[l] > maxHeap[ma])
				ma = l;
			if (r < size() && maxHeap[r] > maxHeap[ma])
				ma = r;
			if (ma == i)
				break;
			swap(maxHeap[i], maxHeap[ma]);
			// ѭ�����¶ѻ�
			i = ma;
		}
	}
};