#include "iostream"
#include "string"
using namespace std;

/*加法哈希*/
int addHash(string key){
	long long hash = 0;
	/*1000000007 是一个质数，使用质数作为模数可以减少哈希冲突的概率*/
	/*避免内存溢出，保证结果在int整数范围内*/
	const int MODULE = 1000000007;
	/*使用unsigned char保证字符转换后都为正数，避免了减法的发生*/
	for (unsigned char ch : key){
		hash = (hash + (int)ch) % MODULE;
	}
	return (int)hash;
}
/*乘法哈希*/
int mulHash(string key){
	long long hash = 0;
	const int MODULE = 1000000007;
	for (unsigned char ch : key){
		hash = (31 * hash + (int)ch) % MODULE;
	}
	return (int)hash;
}
/*异或哈希*/
int xorHash(string key){
	long long hash = 0;
	const int MODULE = 1000000007;
	for (unsigned char ch : key){
		hash ^= (int)ch;
	}
	return (int)hash;
}
/*旋转哈希*/
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
	// 整数 3 的哈希值为 3
	bool bol = true;
	size_t hashBol = hash<bool>()(bol);
	// 布尔量 1 的哈希值为 1
	double dec = 3.14159;
	size_t hashDec = hash<double>()(dec);
	// 小数 3.14159 的哈希值为 4614256650576692846
	string str = "Hello 算法";
	// 字符串“Hello 算法”的哈希值为 15466937326284535026
	cout << hash<string>()(key) << endl;

	system("pause");
	return 0;
}