/*
Divide & Conquer
문제를 작은 문제로 나눈 다음 푸는 것
푼 다음 다시 합쳐서 정답을 구할 때도 있다
0. 이분 탐색(Binary Search)
1. 퀵소트
2. 머지소트
3. 큰 수 곱셈(카라추바 알고리즘)
4. FFT
*/
/*
분할 정복과 다이나믹
공통점 - 문제를 작은 부분문제로 나눈다는 점
차이점
분할 정복: 문제가 겹치지 않음
다이나믹: 문제가 겹쳐서 겹치는 것을 Memoization으로 해결, 작은 문제의 값을 저장하고 있어야 함
*/
/*
이분 탐색

while (left <= right) {
	int mid = (left + right) / 2;
	if (a[mid] == x) {
		position = mid;
		break;
	}
	else if (a[mid] > x) {
		right = mid - 1;
	}
	else {
		left = mid + 1;
	}

}
*/
/*
머지 소트 : N개를 정렬하는 알고리즘
전부 나눈 후 마지막에 합친다.
void sort(int start, int end) {
if (start==end)
{
return;
}
int mid = (start + end) / 2;
sort(start, mid);
sort(mid + 1, end);
merge(start, end);
}
*/

// 종이의 개수
#include <cstdio>
int a[3000][3000];
int cnt[3];
bool same(int x, int y, int n) {
	for (int i = x; i<x + n; i++) {
		for (int j = y; j<y + n; j++) {
			if (a[x][y] != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void solve(int x, int y, int n) {
	if (same(x, y, n)) {
		cnt[a[x][y] + 1] += 1;
		return;
	}
	int m = n / 3;
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	solve(0, 0, n);
	for (int i = 0; i<3; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}