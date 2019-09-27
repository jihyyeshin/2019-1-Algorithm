/*


*/
#include <iostream>
using namespace std;
int a[500][500];
bool c[500][500];
// 웬만하면 동적할당 말고 글로벌로
int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };// 방향을 위한 dx, dy
int ans = 0;
/*
다섯개의 테트리미노 중, 하나를 뺀 나머지는 4개의 방향을 연속으로 가면 만들어짐
나머지 하나는 연속 방향으로 해결 안됨, 따라서 그 한개는 따로 반복문 돌릴 것!
*/

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum; // 최대값이면 저장
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return; // 범위를 벗어났을 경우
	if (c[x][y]) return; // 이미 방문한 경우 return
	c[x][y] = true;
	for (int k = 0; k < 4; k++) // 모든 경우를 방문함
		go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
	c[x][y] = false; // BF는 방문한 칸 또 방문함, 하지만 dfs는 또 방문 X
	// 즉 BF는 원래 상태로 돌려주는 코드가 있음
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);
			// ㅜ 모양의 회전
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j+ 1 <m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j- 1 < n) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		
		
		}
	}
}