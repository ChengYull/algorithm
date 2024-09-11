#include  "vector"
#include "iostream"
using namespace std;
class MaxHeap{
public:
	vector<int> maxHeap;

	MaxHeap(){}

	/*构造方法 ， 根据输入列表建堆*/
	MaxHeap(vector<int> nums){
		// 将列表元素原封不动地添加进堆
		maxHeap = nums;
		// 堆化除叶节点外的所有节点
		for (int i = size() - 1; i >= 0; i--){
			siftDown(i);
		}
	}

	/*获取左子节点的索引*/
	int left(int i){
		return 2 * i + 1;
	}
	/*获取右子节点的索引*/
	int right(int i){
		return 2 * i + 2;
	}
	/*获取父节点的索引*/
	int parent(int i){
		return (i - 1) / 2; // 向下整除
	}
	/*访问堆顶元素*/
	int peak(){
		return maxHeap[0];
	}

	/*获取堆长度*/
	int size(){
		return maxHeap.size();
	}

	/*判断是否为空*/
	bool isEmpty(){
		return size() == 0;
	}

	/*元素入堆*/
	void push(int val){
		// 添加节点
		maxHeap.push_back(val);
		// 从底至顶堆化
		siftUp(size() - 1);
	}

	/*从底至顶堆化*/
	void siftUp(int i){
		
		while (true){
			// 获取节点i父节点
			int p = parent(i);
			// 当越过根节点 或 节点无需修复时 结束堆化
			if (p < 0 || maxHeap[i] < maxHeap[p]){
				break;
			}
			// 交换两节点
			swap(maxHeap[i], maxHeap[p]);
			// 循环向上堆化
			i = p;
		}
	}
	/*元素出堆*/
	void pop(){
		// 判空处理
		if (isEmpty()){
			cout << "堆为空" << endl;
			return;
		}
		// 交换堆顶和堆底最右端的元素
		swap(maxHeap[0], maxHeap[size() - 1]);
		// 移除堆底最右端的元素
		maxHeap.pop_back();
		/*从顶至底堆化*/
		siftDown(0);
	}

	/*从顶至底堆化*/
	void siftDown(int i){
		while (true){
			// 判断 i,l,r 中值最大的节点，记为 ma
			int l = left(i), r = right(i), ma = i;
			if (l < size() && maxHeap[l] > maxHeap[ma])
				ma = l;
			if (r < size() && maxHeap[r] > maxHeap[ma])
				ma = r;
			if (ma == i)
				break;
			swap(maxHeap[i], maxHeap[ma]);
			// 循环向下堆化
			i = ma;
		}
	}
};