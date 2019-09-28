#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
// check: 어떤 알파벳을 방문했는가?
int go(vector<string> &board, vector<bool> &check, int x, int y) {
	int ans = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		// 범위안에 있는가?
		if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
			// 방문한 적이 없다면?
			if (check[board[nx][ny] - 'A'] == false) {
				check[board[nx][ny] - 'A'] = true;
				int next = go(board, check, nx, ny);
				if (ans < next) ans = next;
				check[board[nx][ny] - 'A'] == false;
			}
		}
	}
	return ans + 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> board(n); // 알파벳 입력받음
	for (int i = 0; i<n; i++) {
		cin >> board[i];
	}
	vector<bool> check(26); // 알파벳 체크
	check[board[0][0] - 'A'] = true;
	cout << go(board, check, 0, 0) << '\n';
	return 0;
}