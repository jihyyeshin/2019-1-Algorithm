/*
행렬 A를 B로 바꾸기

똑같은 연산을 두 번 할 필요 없다 = 안 한것과 같기 때문
2^2500을 할 수 없음, 각각을 다 파악하려면 총 걸리는 시간..

따라서 4*4행렬에서 안바뀌는 칸을 보고 그 주변의 3*3을 바뀔지 여부를 알 수 있음

*/
#include <iostream>
using namespace std;
int a[50][50];
int b[50][50];
void flip(int x, int y) {
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j < u + 1; j++)
			a[i][j] = 1 - a[i][j];
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i = n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i = n; i++) {
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	}
	// 입력 완료
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; i < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				ans += 1;
				flip(i + 1, j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}