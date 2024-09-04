#include "iostream"
#include "vector"
#include "string"

using namespace std;

/*键值对*/
struct Pair{
	int key;
	string val;
	Pair(int key, string val){
		this->key = key;
		this->val = val;
	}
};

class HashMapOpenAddressing{
private:
	int capacity;									// 哈希表容量
	double loadThres;							// 触发扩容的负载因子阈值
	int extendRatio;							// 扩容倍数
	vector<Pair *> buckets;				// 桶数组
	Pair *TOMBSTONE = new Pair(-1, "-1");// 删除标记
public:
	int size;											// 键值对数量
	/*构造方法*/
	HashMapOpenAddressing() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2){
		buckets.resize(capacity);
	}
	/*析构方法*/
	~HashMapOpenAddressing(){
		for (Pair* pair : buckets){
			if (pair != nullptr && pair != TOMBSTONE){
				delete pair;
			}
		}
		delete TOMBSTONE;
	}
	/*哈希函数*/
	int hashFunc(int key){
		int index = key % capacity;
		return index;
	}
	/*负载因子*/
	double loadFactor(){
		return (double)size / (double)capacity;
	}
	/*搜索key对应的桶索引*/
	int findBucket(int key){
		int index = hashFunc(key);
		int firstTompStone = -1;
		Pair *pair;
		while (buckets[index] != nullptr){
			pair = buckets[index];
			
			if (key == pair->key){
				// 若之前存在删除标记
				if (firstTompStone != -1){
					buckets[firstTompStone] = buckets[index];
					buckets[index] = TOMBSTONE;
					return firstTompStone;
				}
				return index;
			}
			if (firstTompStone == -1 && pair == TOMBSTONE){
				firstTompStone = index;
			}
			// 使其循环遍历 形成环形数组
			index = (index + 1) % capacity;
		}
		// key不存在时，返回哈希函数值最近的空桶（供添加元素使用）
		return firstTompStone == -1 ? index : firstTompStone;
	}
	/*查询操作*/
	string get(int key){
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE)
			return (buckets[index]->val);
		return "";
	}
	/*添加操作*/
	void put(int key, string val){
		if (loadFactor() > loadThres)
			extend();
		int index = findBucket(key);
		// 找到已存在的key值 直接覆盖
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE){
			buckets[index]->val = val;
			return;
		}
		// 不存在则新增键值对
		buckets[index] = new Pair(key, val);
		size++;

	}
	/*删除操作*/
	void remove(int key){
		int index = findBucket(key);
		// 找到键值对
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE){
			delete buckets[index];
			buckets[index] = TOMBSTONE;
			size--;
		}else{
			cout << "不存在该键值对" << endl;
		}
	}
	/*扩容哈希表*/
	void extend(){
		// 暂存原哈希表
		vector<Pair *> bucketsTmp = buckets;
		// 初始化扩容后的新哈希表
		capacity *= extendRatio;
		buckets = vector<Pair*>(capacity, nullptr);
		size = 0;
		// 将键值对从原哈希表搬运至新哈希表
		for (Pair* pair : bucketsTmp){
			if (pair != nullptr && pair != TOMBSTONE){
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}
	/*打印哈希表*/
	void print(){
		for (Pair* pair : buckets){
			if (pair != nullptr && pair != TOMBSTONE)
				cout << pair->key << "->" << pair->val << endl;
			
		}
	}
};

int main(){
	HashMapOpenAddressing *OAmap = new HashMapOpenAddressing();
	OAmap->put(123, "张三");
	OAmap->put(154, "李四");
	OAmap->put(198, "王麻子");
	OAmap->put(244, "牛魔");
	OAmap->put(388, "诗人");
	OAmap->print();
	
	cout << "====删除====" << endl;
	OAmap->remove(154);
	OAmap->print();
	cout << "==========" << endl;
	cout << "大小：" << OAmap->size << endl;
	cout << "====查询====" << endl;
	cout << "198 ->" << OAmap->get(198) << endl;
	system("pause");
	return 0;
}