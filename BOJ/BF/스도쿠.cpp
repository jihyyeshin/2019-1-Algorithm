#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n = 9;
int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}
bool go(int z) {
	if (z == 81) { // 전부 채웠을 때 출력
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}
	// 행, 열
	int x = z / n;
	int y = z % n;
	if (a[x][y] != 0) { // 이미 채워져있다면, 다음 것으로
		return go(z + 1);
	}
	else { // 채워져있지 않은 경우
		for (int i = 1; i <= 9; i++) {// 1부터 9까지 넣어봄
			// 행, 열, 3*3칸에 다 없는 경우
			if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
				a[x][y] = i;
				if (go(z + 1)) { // false가 하나라도 날 경우,
					// 그 값으로는 스도쿠를 다 채울 수 없다는 뜻이므로
					// 전부 true가 될 때 까지!
					return true;
				}
				a[x][y] = 0;
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				c[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i, j)][a[i][j]] = true;
			}
		}
	}
	go(0);
	return 0;
}