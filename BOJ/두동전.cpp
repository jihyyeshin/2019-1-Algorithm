/*
1. 불가능한 경우
step==11
두 동전 모두 떨어진 경우
2. 정답
두 동전 중 하나만 떨어진 경우
3. 다음 경우는?
버튼 누르는 경우를 처리해준다.
*/
#include <iostream>
#include <string>
using namespace std;
int n, m;
string a[20];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
// 동전의 위치만 변하니까, 동전의 위치만 인자로 넣음
int go(int step, int x1, int y1, int x2, int y2) {
	if (step == 11) return -1;
	bool fall1 = false, fall2 = false;
	// 동전이 떨어졌는지 구해서, 만약에 둘다면 -1, 하나만이면 step
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
	if (fall1&&fall2) return -1;
	if (fall1 || fall2) return step;
	int ans = -1;
	// 이동해야 하는 경로
	for (int k = 0; k < 4; k++) {
		int nx1 = x1 + dx[k];
		int ny1 = y1 + dy[k];
		int nx2 = x2 + dx[k];
		int ny2 = y2 + dy[k];
		// 벽이면 이동하지 않음
		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m&&a[nx1][ny1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m&&a[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}

		int temp = go(step + 1, nx1, ny1, nx2, ny2);
		if (temp == -1) continue; // 불가능한 경우 넘어가기
		if (ans == -1 || ans > temp)
			ans = temp;
	}
	return ans;
}


int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {// 동전 1, 2의 위치를 각각 넣어놓음
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
				a[i][j] = '.';// 동전이 있는 자리도 결국엔 빈자리이므로
			}
		}
	}
	cout << go(0, x1, y1, x2, y2) << '\n';
	return 0;
}