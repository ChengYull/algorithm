#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

using namespace std;

void testMap(){
	/*初始化哈希表*/
	unordered_map<int, string> map;

	/*添加操作*/
	// 在哈希表中添加键值对（key，value）
	map[123] = "张三";
	map[110] = "李四";
	map[188] = "王五";
	map[178] = "赵六";
	map[198] = "悟空";

	/*查询操作*/
	// 向哈希表中输入键 key 得到值 value
	string name = map[188];
	cout << "姓名：" << name << endl;

	/*删除操作*/
	// 在哈希表中根据键key删除键值对
	map.erase(188);


	/*遍历哈希表*/
	// 遍历键值对 kay -> value
	for (auto kv : map){
		cout << kv.first << " -> " << kv.second << endl;
	}
	// 使用迭代器遍历key -> value
	for (auto iter = map.begin(); iter != map.end(); iter++){
		cout << iter->first << " -> " << iter->second << endl;
	}
}

/*键值对*/
struct Pair{
	int key;
	string val;
	Pair(int key, string val){
		this->key = key;
		this->val = val;
	}
};
/*基于数组实现的哈希表*/
class ArrayHashMap{
private:
	vector<Pair*> buckets;
public:
	ArrayHashMap(){
		// 初始化数组，包含100个桶
		buckets = vector<Pair*>(100);
	}
	~ArrayHashMap(){
		// 释放内存
		for (const auto &bucket : buckets){
			delete bucket;
		}
		buckets.clear();
	}
	/*哈希函数*/
	int hashFunc(int key){
		return key % 100;
	}
	/*查询操作*/
	string get(int key){
		int index = hashFunc(key);
		Pair *pair = buckets[index];
		if (pair == nullptr)
			return "";
		return pair->val;
	}
	/*添加操作*/
	void put(int key, string val){
		Pair *pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;		
	}
	/*删除操作*/
	void remove(int key){
		int index = hashFunc(key);
		/*迭代器方式删除
		auto iter = buckets.begin();
		iter += index;
		buckets.erase(iter);*/
		// 置空方式删除
		delete buckets[index];
		buckets[index] = nullptr;
	}
	/*获取所有键值对*/
	vector<Pair*> pairSet(){
		vector<Pair*> pair_set;
		for (Pair* pair:buckets){
			if (pair)
				pair_set.push_back(pair);
		}
		return pair_set;
	}
	/*获取所有键*/
	vector<int> keySet(){
		vector<int> key_set;
		for (Pair* pair : buckets){
			if (pair)
				key_set.push_back(pair->key);
		}
		return key_set;
	}
	/*获取所有值*/
	vector<string> valueSet(){
		vector<string> val_set;
		for (Pair* pair : buckets){
			if (pair)
				val_set.push_back(pair->val);
		}
		return val_set;
	}
	/*打印哈希表*/
	void print(){
		for (Pair* pair : pairSet()){
			cout << pair->key << "->" << pair->val << endl;
		}
	}
};

void testArrayHashMap(){
	ArrayHashMap *arrMap = new ArrayHashMap();
	arrMap->put(12345, "张三");
	arrMap->put(12377, "李四");
	arrMap->put(12355, "牛魔");
	arrMap->print();
	cout << "-----------" <<endl;
	arrMap->remove(12355);
	arrMap->print();
	string name = arrMap->get(12345);
	cout << "姓名：" << name << endl;
}

int main1(){

	testMap();
	cout << "========================" << endl;
	testArrayHashMap();

	system("pause");
	return 1;
}