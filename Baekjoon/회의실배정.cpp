/*
1. ª�� ȸ�Ǹ� ���� �ϸ� ?
2. ���� �����ϴ� ȸ�Ǹ� ���� ?
: ���� �ݷʰ� ������ - �ݷʰ� ������ ���� Ǯ �� ����
���� - ���� ������ ȸ�Ǻ��� ���� !
*/

/*
Algorithm - Sort

sort(start, end)�� start-end ������ ���ڸ� ������������ ����
�� ���� ��� - nlogn

sort(start, end, compare comp)�� 3��° ���ڿ� ����ڰ� ������ �Լ��� �������� ���� ����
*/
#include <vector>
#include <algorithm> // algorithm �� sort�� �̿�
#include <iostream>
using namespace std;
// ����ü ����
struct Meeting {
	int begin, end;
};
// �� ���� ������ ���Ѵ�.
bool cmp(const Meeting &u, const Meeting &v) {
	if (u.end == v.end) {// end�� ������, begin�� ���� ��
		return u.begin < v.begin;
	}
	else {// end�� �ٸ���, end�� ���� ��
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
	sort(a.begin(), a.end(), cmp); // a�� ���ۺ��� ������ �����Ѵ�
	int now = 0;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {// begin, end ���̿��� �� �� �ִ� ��ŭ ����, ������ �߱� ������ ����ȭ�� ans�� ã�� �� ����
			now = a[i].end;
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}