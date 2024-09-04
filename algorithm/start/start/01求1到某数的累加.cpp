#include "iostream"
#include "vector"
using namespace std;
/************************************************************************/
/* 求1+2+3+... +n的和                                                                     */
/************************************************************************/
int forLoop(int n){
	int res = 0;
	// 循环求和 1,2,3,4...,n
	for (int i = 1; i <= n; i++){
		res += i;
	}
	return res;
}
/*while 循环*/
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
/* “编写一个函数 nestedForLoop，该函数接收一个整数 n 作为参数，n < 1*10^9
并返回一个字符串。这个字符串应该包含所有在 n x n 网格中点的坐标，
每个坐标以 ‘(i, j),’ 的格式排列，其中 i 和 j 分别是点的行号和列号，
范围从 1 到 n。坐标之间用逗号和空格分隔，字符串的最后一个坐标
后也应该有一个逗号和空格。”                                                                     */
/************************************************************************/
/* 双层 for 循环 */
//char *nestedForLoop(int n) {
//	// n * n 为对应点数量，"(i, j), " 对应字符串长最大为 6+10*2，加上最后一个空字符 \0 的额外空间
//	int size = n * n * 26 + 1;
//	char *res = malloc(size * sizeof(char));
//	// 循环 i = 1, 2, ..., n-1, n
//	for (int i = 1; i <= n; i++) {
//		// 循环 j = 1, 2, ..., n-1, n
//		for (int j = 1; j <= n; j++) {
//			char tmp[26];
//			snprintf(tmp, sizeof(tmp), "(%d, %d), ", i, j);
//			strncat(res, tmp, size - strlen(res) - 1);
//		}
//	}
//	return res;
//}
/*递归调用*/
int recur(int n){
	if (n == 1){
		return 1;
	}
	return n + recur(n - 1);
}
/*尾递归*/
int tailRecur(int n, int res){
	// 终止条件
	if (n == 0)
		return res;
	// 尾递归调用
	return tailRecur(n - 1, res + n);
}
/*斐波那契数列的第n个数字  0,1,1,2,3,5,8......  */
int fib(int n){
	if (n == 2 || n == 1)
		return n - 1;
	return fib(n - 1) + fib(n - 2);
}

// 在某运行平台下
void algorithm(int n) {
	int a = 2; // 1 ns
	a = a + 1; // 1 ns
	a = a * 2; // 10 ns
	// 循环 n 次
	for (int i = 0; i < n; i++) { // 1 ns ，每轮都要执行 i++
		std::cout << 0 << std::endl; // 5 ns
	}
}

void algorithm(int n) {
	int a = 1; // +0（技巧 1）
	a = a + n; // +0（技巧 1）
	// +n（技巧 2）
	for (int i = 0; i < 5 * n + 1; i++) {
		cout << 0 << endl;
	}
	// +n*n（技巧 3）
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << 0 << endl;
		}
	}
}
/*平方阶-冒泡排序*/
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

/* 指数阶（循环实现） */
int exponential(int n) {
	int count = 0, base = 1;
	// 细胞每轮一分为二，形成数列 1, 2, 4, 8, ..., 2^(n-1)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < base; j++) {
			count++;
		}
		base *= 2;
	}
	// count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
	return count;
}
/* 指数阶（递归实现） */
int expRecur(int n) {
	if (n == 1)
		return 1;
	return expRecur(n - 1) + expRecur(n - 1) + 1;
}

/* 对数阶（递归实现） */
int logRecur(int n) {
	if (n <= 1)
		return 0;
	return logRecur(n / 2) + 1;
}

/* 阶乘阶（递归实现） */
int factorialRecur(int n) {
	if (n == 0)
		return 1;
	int count = 0;
	// 从 1 个分裂出 n 个
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

/* 函数 */
int func() {
	// 执行某些操作
	return 0;
}
/* 常数阶 */
void constant(int n) {
	// 常量、变量、对象占用 O(1) 空间
	const int a = 0;
	int b = 0;
	vector<int> nums(10000);
	ListNode node(0);
	// 循环中的变量占用 O(1) 空间
	for (int i = 0; i < n; i++) {		int c = 0;
	}
	// 循环中的函数占用 O(1) 空间
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