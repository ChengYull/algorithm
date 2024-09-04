#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"

using namespace std;

void testMap(){
	/*��ʼ����ϣ��*/
	unordered_map<int, string> map;

	/*��Ӳ���*/
	// �ڹ�ϣ������Ӽ�ֵ�ԣ�key��value��
	map[123] = "����";
	map[110] = "����";
	map[188] = "����";
	map[178] = "����";
	map[198] = "���";

	/*��ѯ����*/
	// ���ϣ��������� key �õ�ֵ value
	string name = map[188];
	cout << "������" << name << endl;

	/*ɾ������*/
	// �ڹ�ϣ���и��ݼ�keyɾ����ֵ��
	map.erase(188);


	/*������ϣ��*/
	// ������ֵ�� kay -> value
	for (auto kv : map){
		cout << kv.first << " -> " << kv.second << endl;
	}
	// ʹ�õ���������key -> value
	for (auto iter = map.begin(); iter != map.end(); iter++){
		cout << iter->first << " -> " << iter->second << endl;
	}
}

/*��ֵ��*/
struct Pair{
	int key;
	string val;
	Pair(int key, string val){
		this->key = key;
		this->val = val;
	}
};
/*��������ʵ�ֵĹ�ϣ��*/
class ArrayHashMap{
private:
	vector<Pair*> buckets;
public:
	ArrayHashMap(){
		// ��ʼ�����飬����100��Ͱ
		buckets = vector<Pair*>(100);
	}
	~ArrayHashMap(){
		// �ͷ��ڴ�
		for (const auto &bucket : buckets){
			delete bucket;
		}
		buckets.clear();
	}
	/*��ϣ����*/
	int hashFunc(int key){
		return key % 100;
	}
	/*��ѯ����*/
	string get(int key){
		int index = hashFunc(key);
		Pair *pair = buckets[index];
		if (pair == nullptr)
			return "";
		return pair->val;
	}
	/*��Ӳ���*/
	void put(int key, string val){
		Pair *pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;		
	}
	/*ɾ������*/
	void remove(int key){
		int index = hashFunc(key);
		/*��������ʽɾ��
		auto iter = buckets.begin();
		iter += index;
		buckets.erase(iter);*/
		// �ÿշ�ʽɾ��
		delete buckets[index];
		buckets[index] = nullptr;
	}
	/*��ȡ���м�ֵ��*/
	vector<Pair*> pairSet(){
		vector<Pair*> pair_set;
		for (Pair* pair:buckets){
			if (pair)
				pair_set.push_back(pair);
		}
		return pair_set;
	}
	/*��ȡ���м�*/
	vector<int> keySet(){
		vector<int> key_set;
		for (Pair* pair : buckets){
			if (pair)
				key_set.push_back(pair->key);
		}
		return key_set;
	}
	/*��ȡ����ֵ*/
	vector<string> valueSet(){
		vector<string> val_set;
		for (Pair* pair : buckets){
			if (pair)
				val_set.push_back(pair->val);
		}
		return val_set;
	}
	/*��ӡ��ϣ��*/
	void print(){
		for (Pair* pair : pairSet()){
			cout << pair->key << "->" << pair->val << endl;
		}
	}
};

void testArrayHashMap(){
	ArrayHashMap *arrMap = new ArrayHashMap();
	arrMap->put(12345, "����");
	arrMap->put(12377, "����");
	arrMap->put(12355, "ţħ");
	arrMap->print();
	cout << "-----------" <<endl;
	arrMap->remove(12355);
	arrMap->print();
	string name = arrMap->get(12345);
	cout << "������" << name << endl;
}

int main1(){

	testMap();
	cout << "========================" << endl;
	testArrayHashMap();

	system("pause");
	return 1;
}