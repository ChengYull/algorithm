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

class HashMapChaining{
private:

	int capacity;									// 哈希表容量
	double loadThres;							// 触发扩容的负载因子阈值
	int extendRatio;							// 扩容倍数
	vector<vector<Pair*>> buckets; // 桶数组
public:
	int size;											// 键值对数量
	/*构造方法*/
	HashMapChaining() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2){
		buckets.resize(capacity);
	}
	/*析构方法*/
	~HashMapChaining(){
		for (auto &bucket : buckets){
			for (Pair *pair : bucket){
				//释放内存
				delete pair;
			}
		}
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
	/*查询操作*/
	string get(int key){
		int index = hashFunc(key);
		if (buckets[index].size() == 0)
			return "";
		for (Pair * pair : buckets[index]){
			if (key == pair->key)
				return pair->val;
		}
		return "";
	}
	/*添加操作*/
	void put(int key, string val){
		if (loadFactor() > loadThres)
			extend();
		Pair * pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index].push_back(pair);
		size++;
	}
	/*删除操作*/
	void remove(int key){
		int index = hashFunc(key);
		for (auto iter = buckets[index].begin(); iter != buckets[index].end();iter++){
			if (key == (*iter)->key){
				buckets[index].erase(iter);
				size--;
				return;
			}
		}
		cout << "未找到该元素" << endl;
	}
	/*扩容哈希表*/
	void extend(){
		buckets.resize(extendRatio * capacity);
		capacity *= extendRatio;
	}
	/*打印哈希表*/
	void print(){
		for (auto &bucket : buckets){
			for (Pair *pair : bucket){
				cout << pair->key << "->" << pair->val << endl;
			}
		}
	}
};

int main2(){

	HashMapChaining *chainMap = new HashMapChaining();
	chainMap->put(123, "张三");
	chainMap->put(178, "李四");
	chainMap->put(169, "王麻子");
	chainMap->put(125, "牛魔");
	chainMap->put(134, "悟空");
	chainMap->print();
	cout << "=================" << endl;
	chainMap->remove(169);
	chainMap->print();
	cout << "=================" << endl;
	cout << "名字：" << chainMap->get(125) << endl;
	cout << "=================" << endl;
	cout << "大小：" << chainMap->size << endl;
	system("pause");
	return 0;
}