#include <iostream>
using namespace std;
bool c[20 * 100000 + 10];
int a[20];
int n;
// 부분 수열을 만들었을 때 그 합이 되는 수에는 true를 만들어준다.
void go(int i, int sum) {
	if (i == n) { // i를 만들 수 있을 때 true
		c[sum] = true;
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);

	for(int i=1;;i++){
		if (c[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}