/*
�Ŀ� ��ȣ�� ������ �ļ� ���� ���� �ּҷ� ����� ����
: -�� ������, �׻� ���� ���� -�� ���� �� ����: �� �� �ּҰ� ��
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	// �Է� ���� ����
	string s;
	cin >> s;
	// num : ����, sign : ��ȣ
	vector<int> num;
	vector<int> sign;
	// minus�� true�� ���, �� ���� ���� �ȴ�.
	bool minus = false;
	int cur = 0;
	// sign�� plus�� 1, minus�� -1�� ����
	// ó���� 1�� �ִ� ������, �� ó������ +��ȣ ���� +�� �ǹ��ϱ� ����!
	sign.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		// ���� ��ü�� ���Ͽ� ��ȣ(p&m), ���ڸ� �����ϰ� ���� sign, num�� ����
		if (s[i] == '+' || s[i] == '-') {
			// ��ȣ�� ���, �� ��ȣ�� ���� ���� 1, -1�� �־��ش�
			if (s[i] == '+') {
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			// ��ȣ�� ������ �� ������ ���� ���ڸ� num�� �ְ� �ٽ� ���ڸ� �ʱ�ȭ ��Ŵ!
			num.push_back(cur);
			cur = 0;
		}
		else {
			/*
			������ ���, ���ڰ��� �־��ֵ� 1�� �ڸ� ����� ������ ���� ������
			��, �� ... ���� �ڸ� ���� ������ ���� ó���ϱ� ���� ���� �κ�
			*/
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);
	int ans = 0;
	minus = false;
	// �ּڰ��� �ǵ��� ó�����ֱ� ���� ���� ! 
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus) {
			ans -= num[i];
		}
		else {
			ans += num[i];
		}
	}
	cout << ans << '\n';
	return 0;
}