/*
ATM 
��������(non-decreasing)���� Ǫ�� ���� ���� - S<=S'

greedy�� ���� ��� ���� �߿��ϴ�!
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	// �Է�
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	// ������������ ����
	sort(a.begin(), a.end());
	int sum = 0;
	int ans = 0;
	// �տ��� ���� ���� ��
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans += sum;
	}
	cout << ans << '\n';
	return 0;
}