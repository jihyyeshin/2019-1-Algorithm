/*
��� A�� B�� �ٲٱ�

�Ȱ��� ������ �� �� �� �ʿ� ���� = �� �ѰͰ� ���� ����
2^2500�� �� �� ����, ������ �� �ľ��Ϸ��� �� �ɸ��� �ð�..

���� 4*4��Ŀ��� �ȹٲ�� ĭ�� ���� �� �ֺ��� 3*3�� �ٲ��� ���θ� �� �� ����

*/
#include <iostream>
using namespace std;
int a[50][50];
int b[50][50];
void flip(int x, int y) {
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j < u + 1; j++)
			a[i][j] = 1 - a[i][j];
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i = n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i = n; i++) {
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	}
	// �Է� �Ϸ�
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; i < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				ans += 1;
				flip(i + 1, j + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}