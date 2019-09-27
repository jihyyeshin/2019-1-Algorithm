/*
���

k���� ���� �� �� �� 6���� ���� ����
k<=12, 2^12�� ����� ��
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;// �Լ��� �� ��
void solve(vector<int> &a, int index, int cnt) {
	if (cnt == 6) { // 6�� ������� ���
		for (int num : lotto)
			cout << num;
		cout << '\n';
		return;
	}
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);// index��°�� ������ ���
	solve(a, index + 1, cnt + 1);
	lotto.pop_back();// index��°�� �������� ���� ���
	solve(a, index + 1, cnt);

}
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}