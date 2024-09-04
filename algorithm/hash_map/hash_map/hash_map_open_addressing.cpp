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

class HashMapOpenAddressing{
private:
	int capacity;									// ��ϣ������
	double loadThres;							// �������ݵĸ���������ֵ
	int extendRatio;							// ���ݱ���
	vector<Pair *> buckets;				// Ͱ����
	Pair *TOMBSTONE = new Pair(-1, "-1");// ɾ�����
public:
	int size;											// ��ֵ������
	/*���췽��*/
	HashMapOpenAddressing() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2){
		buckets.resize(capacity);
	}
	/*��������*/
	~HashMapOpenAddressing(){
		for (Pair* pair : buckets){
			if (pair != nullptr && pair != TOMBSTONE){
				delete pair;
			}
		}
		delete TOMBSTONE;
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
	/*����key��Ӧ��Ͱ����*/
	int findBucket(int key){
		int index = hashFunc(key);
		int firstTompStone = -1;
		Pair *pair;
		while (buckets[index] != nullptr){
			pair = buckets[index];
			
			if (key == pair->key){
				// ��֮ǰ����ɾ�����
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
			// ʹ��ѭ������ �γɻ�������
			index = (index + 1) % capacity;
		}
		// key������ʱ�����ع�ϣ����ֵ����Ŀ�Ͱ�������Ԫ��ʹ�ã�
		return firstTompStone == -1 ? index : firstTompStone;
	}
	/*��ѯ����*/
	string get(int key){
		int index = findBucket(key);
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE)
			return (buckets[index]->val);
		return "";
	}
	/*��Ӳ���*/
	void put(int key, string val){
		if (loadFactor() > loadThres)
			extend();
		int index = findBucket(key);
		// �ҵ��Ѵ��ڵ�keyֵ ֱ�Ӹ���
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE){
			buckets[index]->val = val;
			return;
		}
		// ��������������ֵ��
		buckets[index] = new Pair(key, val);
		size++;

	}
	/*ɾ������*/
	void remove(int key){
		int index = findBucket(key);
		// �ҵ���ֵ��
		if (buckets[index] != nullptr && buckets[index] != TOMBSTONE){
			delete buckets[index];
			buckets[index] = TOMBSTONE;
			size--;
		}else{
			cout << "�����ڸü�ֵ��" << endl;
		}
	}
	/*���ݹ�ϣ��*/
	void extend(){
		// �ݴ�ԭ��ϣ��
		vector<Pair *> bucketsTmp = buckets;
		// ��ʼ�����ݺ���¹�ϣ��
		capacity *= extendRatio;
		buckets = vector<Pair*>(capacity, nullptr);
		size = 0;
		// ����ֵ�Դ�ԭ��ϣ��������¹�ϣ��
		for (Pair* pair : bucketsTmp){
			if (pair != nullptr && pair != TOMBSTONE){
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}
	/*��ӡ��ϣ��*/
	void print(){
		for (Pair* pair : buckets){
			if (pair != nullptr && pair != TOMBSTONE)
				cout << pair->key << "->" << pair->val << endl;
			
		}
	}
};

int main(){
	HashMapOpenAddressing *OAmap = new HashMapOpenAddressing();
	OAmap->put(123, "����");
	OAmap->put(154, "����");
	OAmap->put(198, "������");
	OAmap->put(244, "ţħ");
	OAmap->put(388, "ʫ��");
	OAmap->print();
	
	cout << "====ɾ��====" << endl;
	OAmap->remove(154);
	OAmap->print();
	cout << "==========" << endl;
	cout << "��С��" << OAmap->size << endl;
	cout << "====��ѯ====" << endl;
	cout << "198 ->" << OAmap->get(198) << endl;
	system("pause");
	return 0;
}