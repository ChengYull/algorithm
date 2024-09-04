#include "iostream"
#include "vector"
#include "string"

using namespace std;

/*��ֵ��*/
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

	int capacity;									// ��ϣ������
	double loadThres;							// �������ݵĸ���������ֵ
	int extendRatio;							// ���ݱ���
	vector<vector<Pair*>> buckets; // Ͱ����
public:
	int size;											// ��ֵ������
	/*���췽��*/
	HashMapChaining() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2){
		buckets.resize(capacity);
	}
	/*��������*/
	~HashMapChaining(){
		for (auto &bucket : buckets){
			for (Pair *pair : bucket){
				//�ͷ��ڴ�
				delete pair;
			}
		}
	}
	/*��ϣ����*/
	int hashFunc(int key){
		int index = key % capacity;
		return index;
	}

	/*��������*/
	double loadFactor(){
		return (double)size / (double)capacity;
	}
	/*��ѯ����*/
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
	/*��Ӳ���*/
	void put(int key, string val){
		if (loadFactor() > loadThres)
			extend();
		Pair * pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index].push_back(pair);
		size++;
	}
	/*ɾ������*/
	void remove(int key){
		int index = hashFunc(key);
		for (auto iter = buckets[index].begin(); iter != buckets[index].end();iter++){
			if (key == (*iter)->key){
				buckets[index].erase(iter);
				size--;
				return;
			}
		}
		cout << "δ�ҵ���Ԫ��" << endl;
	}
	/*���ݹ�ϣ��*/
	void extend(){
		buckets.resize(extendRatio * capacity);
		capacity *= extendRatio;
	}
	/*��ӡ��ϣ��*/
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
	chainMap->put(123, "����");
	chainMap->put(178, "����");
	chainMap->put(169, "������");
	chainMap->put(125, "ţħ");
	chainMap->put(134, "���");
	chainMap->print();
	cout << "=================" << endl;
	chainMap->remove(169);
	chainMap->print();
	cout << "=================" << endl;
	cout << "���֣�" << chainMap->get(125) << endl;
	cout << "=================" << endl;
	cout << "��С��" << chainMap->size << endl;
	system("pause");
	return 0;
}