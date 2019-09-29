#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int board[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
	int r, c, t, buf, buf2;
	int result = 0;
	vector<pair<int, int>> mise;
	int gong;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)
				gong = i;// �ڿ����� ����� ����
			else if(board[i][j]!=0)
				mise.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < mise.size(); j++) {
			int cnt = 0;
			buf = board[mise[j].first][mise[j].second];
			for (int k = 0; k < 4; k++) {
				int nx = mise[j].first + dx[k];
				int ny = mise[j].second + dy[k];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					if (board[nx][ny] != -1) {
						board[nx][ny] += buf / 5;
						cnt++;
					}
				}
			}
			board[mise[j].first][mise[j].second] = buf - (buf / 5)*cnt;
		}
		//Ȯ�� ��

		cout << '\n';

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}


		// �ݽð�
		buf2 = board[gong - 1][c-1];
		for (int j =c-2; j>=1; j--)
			board[gong - 1][j + 1] = board[gong - 1][j];
		board[gong - 1][1] = 0;//�̼��������� ���� ��
		buf = board[0][c - 1];
		for (int j = 1; j < gong - 1; j++)
			board[j - 1][c - 1] = board[j][c - 1];
		board[gong - 2][c - 1] = buf2;
		buf2 = board[0][0];
		for (int j = 0; j < c - 1; j++)
			board[0][j] = board[0][j+1];
		board[0][c - 2] = buf;
		for (int j = 2; j < gong - 1; j++)
			board[j][0] = board[j-1][0];
		board[1][0] = buf2;

		cout << '\n';

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}

		// �ð�
		buf2 = board[gong][c - 1];
		for (int j = c - 2; j >= 1; j--)
			board[gong][j + 1] = board[gong][j];
		board[gong][1] = 0;//�̼��������� ���� ��

		//buf = board[0][c - 1];
		//for (int j = 1; j < gong - 1; j++)
		//	board[j - 1][c - 1] = board[j][c - 1];
		//board[gong - 2][c - 1] = buf2;
		//buf2 = board[0][0];
		//for (int j = 0; j < c - 1; j++)
		//	board[0][j] = board[0][j + 1];
		//board[0][c - 2] = buf;
		//for (int j = 2; j < gong - 1; j++)
		//	board[j][0] = board[j - 1][0];
		//board[1][0] = buf2;
	}
	cout << '\n';

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j] << ' ';
			result += board[i][j];
		}
		cout << '\n';
	}
	cout << result << '\n';
}