/*
1. 짧은 회의를 많이 하면 ?
2. 일찍 시작하는 회의를 배정 ?
: 각각 반례가 존재함 - 반례가 나오는 순간 풀 수 없음
정답 - 일찍 끝나는 회의부터 배정 !
*/

/*
Algorithm - Sort

sort(start, end)의 start-end 범주의 인자를 오름차순으로 정렬
퀵 정렬 기반 - nlogn

sort(start, end, compare comp)의 3번째 인자에 사용자가 정의한 함수를 기준으로 정렬 가능
*/
#include <vector>
#include <algorithm> // algorithm 의 sort를 이용
#include <iostream>
using namespace std;
// 구조체 생성
struct Meeting {
	int begin, end;
};
// 두 개의 미팅을 비교한다.
bool cmp(const Meeting &u, const Meeting &v) {
	if (u.end == v.end) {// end가 같으면, begin이 빠른 순
		return u.begin < v.begin;
	}
	else {// end가 다르면, end가 빠른 순
		return u.end < v.end;
	}
}
int main() {
	int n;
	cin >> n;
	vector<Meeting> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].begin >> a[i].end;
	}
	sort(a.begin(), a.end(), cmp); // a의 시작부터 끝까지 정렬한다
	int now = 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {// begin, end 사이에서 들어갈 수 있는 만큼 넣음, 정렬을 했기 때문에 최적화된 ans를 찾을 수 있음
			now = a[i].end;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}