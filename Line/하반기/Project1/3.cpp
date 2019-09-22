#include <iostream>
#include <algorithm>
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

int main() {
	int n, index;
	cin >> n;
	int *arrX = new int[n];
	int *arrY = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arrX[i];
		cin >> arrY[i];
	}
	
}