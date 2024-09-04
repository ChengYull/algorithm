#include "iostream"
#include "string"
using namespace std;

/*�ӷ���ϣ*/
int addHash(string key){
	long long hash = 0;
	/*1000000007 ��һ��������ʹ��������Ϊģ�����Լ��ٹ�ϣ��ͻ�ĸ���*/
	/*�����ڴ��������֤�����int������Χ��*/
	const int MODULE = 1000000007;
	/*ʹ��unsigned char��֤�ַ�ת����Ϊ�����������˼����ķ���*/
	for (unsigned char ch : key){
		hash = (hash + (int)ch) % MODULE;
	}
	return (int)hash;
}
/*�˷���ϣ*/
int mulHash(string key){
	long long hash = 0;
	const int MODULE = 1000000007;
	for (unsigned char ch : key){
		hash = (31 * hash + (int)ch) % MODULE;
	}
	return (int)hash;
}
/*����ϣ*/
int xorHash(string key){
	long long hash = 0;
	const int MODULE = 1000000007;
	for (unsigned char ch : key){
		hash ^= (int)ch;
	}
	return (int)hash;
}
/*��ת��ϣ*/
int rotHash(string key){
	long long hash = 0;
	const int MODULE = 1000000007;
	for (unsigned char ch : key){
		hash = ((hash << 4)^(hash >> 28) ^ (int)ch) % MODULE;
	}
	return (int)hash;
}

int main(){
	string key = "1234qQ";
	int encrypt = rotHash(key);
	cout << key << "->" << encrypt << endl;
	string key1 = "1234qQ";
	int encrypt1 = rotHash(key1);
	cout << key1 << "->" << encrypt1 << endl;

	int num = 3;
	size_t hashNum = hash<int>()(num);
	// ���� 3 �Ĺ�ϣֵΪ 3
	bool bol = true;
	size_t hashBol = hash<bool>()(bol);
	// ������ 1 �Ĺ�ϣֵΪ 1
	double dec = 3.14159;
	size_t hashDec = hash<double>()(dec);
	// С�� 3.14159 �Ĺ�ϣֵΪ 4614256650576692846
	string str = "Hello �㷨";
	// �ַ�����Hello �㷨���Ĺ�ϣֵΪ 15466937326284535026
	cout << hash<string>()(key) << endl;

	system("pause");
	return 0;
}