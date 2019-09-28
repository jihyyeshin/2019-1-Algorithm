/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

한 행에 한 개 이상 올 수 없음
*/

#include <iostream>
using namespace std;
bool a[15][15]; // N의 최대개수 15
int n;
// bool 초기화 안해주면 false인듯
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];
bool check(int row, int col) {
	// 열에 있는가?
	if (check_col[col])
		return false;
	// 대각선에 있는가?
	if (check_dig[row + col])
		return false;
	if (check_dig2[row - col + n])
		return false;
	return true;
}

int calc(int row) {
	if (row == n)
		return 1;
	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {// 이 자리에 퀸이 올 수 있는가?
			// 만일 올 수 있다면, 여오게 해놓고 그 주변자리 다 true로 만들기
			// 대각선 값과
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			// 그 열
			check_col[col] = true;
			// 그 값
			a[row][col] = true;
			cnt += calc(row + 1);
			// 방법+1 했으면 이제 초기화시키기
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}
int main() {
	cin >> n;
	cout << calc(0) << '\n';
	return 0;

}