#include <iostream>
#define MAX 7
using namespace std;

int n, m, result, buf;
int map[MAX][MAX];
int dx[] = { 1, 1, 1 };
int dy[] = { -1, 0, 1 };

void go(int map[][MAX], int x, int y, int before) {
	for (int i = 0; i < 3; i++) {
		if (i == before) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == n) {
			if (buf > result)
				buf = result;
			return;
		}
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			result += map[nx][ny];
			go(map, nx, ny, i);
			result -= map[nx][ny];
		}
	}
}

int main() {
	int ans = 2147483647;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	// 입력 완료
	for (int i = 0; i < m; i++) {
		result = map[0][i];
		buf = 2147483647;
		go(map, 0, i, -1);
		if (ans > buf) ans = buf;
	}
	cout << ans << '\n';
	return 0;
}
