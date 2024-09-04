#include "iostream"
#include "vector"
using namespace std;
/************************************************************************/
/* ��1+2+3+... +n�ĺ�                                                                     */
/************************************************************************/
int forLoop(int n){
	int res = 0;
	// ѭ����� 1,2,3,4...,n
	for (int i = 1; i <= n; i++){
		res += i;
	}
	return res;
}
/*while ѭ��*/
int whileLoop(int n){
	int res = 0;
	int i = 1;
	while (i <= n){
		res += i;
		i++;
	}
	return res;
}
/************************************************************************/
/* ����дһ������ nestedForLoop���ú�������һ������ n ��Ϊ������n < 1*10^9
������һ���ַ���������ַ���Ӧ�ð��������� n x n �����е�����꣬
ÿ�������� ��(i, j),�� �ĸ�ʽ���У����� i �� j �ֱ��ǵ���кź��кţ�
��Χ�� 1 �� n������֮���ö��źͿո�ָ����ַ��������һ������
��ҲӦ����һ�����źͿո񡣡�                                                                     */
/************************************************************************/
/* ˫�� for ѭ�� */
//char *nestedForLoop(int n) {
//	// n * n Ϊ��Ӧ��������"(i, j), " ��Ӧ�ַ��������Ϊ 6+10*2���������һ�����ַ� \0 �Ķ���ռ�
//	int size = n * n * 26 + 1;
//	char *res = malloc(size * sizeof(char));
//	// ѭ�� i = 1, 2, ..., n-1, n
//	for (int i = 1; i <= n; i++) {
//		// ѭ�� j = 1, 2, ..., n-1, n
//		for (int j = 1; j <= n; j++) {
//			char tmp[26];
//			snprintf(tmp, sizeof(tmp), "(%d, %d), ", i, j);
//			strncat(res, tmp, size - strlen(res) - 1);
//		}
//	}
//	return res;
//}
/*�ݹ����*/
int recur(int n){
	if (n == 1){
		return 1;
	}
	return n + recur(n - 1);
}
/*β�ݹ�*/
int tailRecur(int n, int res){
	// ��ֹ����
	if (n == 0)
		return res;
	// β�ݹ����
	return tailRecur(n - 1, res + n);
}
/*쳲��������еĵ�n������  0,1,1,2,3,5,8......  */
int fib(int n){
	if (n == 2 || n == 1)
		return n - 1;
	return fib(n - 1) + fib(n - 2);
}

// ��ĳ����ƽ̨��
void algorithm(int n) {
	int a = 2; // 1 ns
	a = a + 1; // 1 ns
	a = a * 2; // 10 ns
	// ѭ�� n ��
	for (int i = 0; i < n; i++) { // 1 ns ��ÿ�ֶ�Ҫִ�� i++
		std::cout << 0 << std::endl; // 5 ns
	}
}

void algorithm(int n) {
	int a = 1; // +0������ 1��
	a = a + n; // +0������ 1��
	// +n������ 2��
	for (int i = 0; i < 5 * n + 1; i++) {
		cout << 0 << endl;
	}
	// +n*n������ 3��
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << 0 << endl;
		}
	}
}
/*ƽ����-ð������*/
int bubbleSort(vector<int> &nums){

	/*for (int i = 0; i < nums.size(); i++){
		for (int j = i + 1; j < nums.size(); j++){
			if (nums[i] > nums[j]){
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}*/
	for (int i = 0; i < nums.size(); i++){
		for (int j = 0; j < nums.size() - i - 1; j++){
			if (nums[j] > nums[j + 1]){
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

/* ָ���ף�ѭ��ʵ�֣� */
int exponential(int n) {
	int count = 0, base = 1;
	// ϸ��ÿ��һ��Ϊ�����γ����� 1, 2, 4, 8, ..., 2^(n-1)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < base; j++) {
			count++;
		}
		base *= 2;
	}
	// count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
	return count;
}
/* ָ���ף��ݹ�ʵ�֣� */
int expRecur(int n) {
	if (n == 1)
		return 1;
	return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* �����ף��ݹ�ʵ�֣� */
int logRecur(int n) {
	if (n <= 1)
		return 0;
	return logRecur(n / 2) + 1;
}

/* �׳˽ף��ݹ�ʵ�֣� */
int factorialRecur(int n) {
	if (n == 0)
		return 1;
	int count = 0;
	// �� 1 �����ѳ� n ��
	for (int i = 0; i < n; i++) {
		count += factorialRecur(n - 1);
	}
	return count;
}

void algorithm(int n) {
	int a = 0; // O(1)
	vector<int> b(10000); // O(1)
	if (n > 10)
		vector<int> nums(n); // O(n)
}

/* ���� */
int func() {
	// ִ��ĳЩ����
	return 0;
}
/* ������ */
void constant(int n) {
	// ����������������ռ�� O(1) �ռ�
	const int a = 0;
	int b = 0;
	vector<int> nums(10000);
	ListNode node(0);
	// ѭ���еı���ռ�� O(1) �ռ�
	for (int i = 0; i < n; i++) {		int c = 0;
	}
	// ѭ���еĺ���ռ�� O(1) �ռ�
	for (int i = 0; i < n; i++) {
		func();
	}
}

int main(){
	std::cout << "hello world!" << std::endl;
	std::cout << forLoop(100) << std::endl;
	std::cout << recur(100) << std::endl;
	std::cout << fib(7) << std::endl;
	system("pause");
	return 0;
}