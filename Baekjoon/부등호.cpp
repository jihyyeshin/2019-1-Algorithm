/*
브루트포스 - 순열


다 해봐야 할 때,
순서만 변경 가능
*/
/*
1. 한 자리 숫자
2. 모두 달라야 함

10개의 수 중에서 k+1개를 고름 -> (k+1)!의 순서롤 모두 만들고 부등호 검사
- 순서 문제냐 ? 맞음 ! 순서만 바꾸면서 만족시키는지 알아보면 됨
*/

/* 10개 중 k+1개를 고름 2^(k+1) * (k+1)! * (k+1)


# 시간을 줄이는 방법?
수는 정해져있음, 왜 ? k+1이 4일 때
9876, 0123의 조합이 가장 크고 작을 수 밖에 없으니깐
(k+1)!*(k+1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &perm, vector<char> &a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '<' && perm[i] > perm[i + 1])
			return false;
		if (a[i] == '>' && perm[i] < perm[i + 1])
			return false;
	}
	return true;
}
int main() {
	int k;
	cin >> k;
	vector<char> a(k);
	for (int i = 0; i < k; i++)
		cin >> a[i];
	vector<int> small(k + 1);
	vector<int> big(k + 1);
	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}
	do {
		if (check(small, a)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	do {
		if (check(big, a)) {
			break;
		}
	} while (prev_permutation(small.begin(), small.end()));
	for (int i = 0; i < big.size(); i++)
		cout << big[i];
	cout << '\n';
	for (int i = 0; i < small.size(); i++)
		cout << small[i];
}