#include <iostream>
#include <string.h>
using namespace std;

int min(int a[], int len) {// index return
	int buf = 2147483647;
	int result;
	for (int i = 0; i < len; i++) {
		if (a[i] < buf) {
			buf = a[i];
			result = i;
		}
	}
	return result;
}

int max(int a[], int len) {// value return
	int result=0;
	for (int i = 0; i < len; i++) {
		if (a[i] > result) {
			result = a[i];
		}
	}
	return result;
}

int main() {
	int m, c;//둘 다 최대 10개
	cin >> m >> c;
	int *result = new int[c];
	for (int i = 0; i < c; i++)
		result[i] = 0;
	int *input = new int[m];
	for (int i = 0; i < m; i++)
		cin >> input[i];
	// 입력완료
	for (int i = 0; i < m; i++){
		result[min(result, c)] += input[i];
	}

	cout << max(result, c) << '\n';
}