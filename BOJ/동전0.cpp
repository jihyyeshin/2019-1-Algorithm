/*
�׸��� �˰���

�����ؾ� �� ��, �� ������ ���� ���ٰ� �����ϴ� ���� �����ϸ鼭 ���� ã�ư�
�� �� �� ���� ���������� ������, ���������δ� ������ �ƴ� �� �ִ�.

https://www.acmicpc.net/problem/11047
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);//���� vector�� �����
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//�Է� ��
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += k / a[i];//�ڿ��� ���� ��ȸ
		k %= a[i];
	}
	cout << ans << '\n';
	return 0;
}