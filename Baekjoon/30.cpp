/*
30 = 2*3*5
2�� ���: 0, 2, 4, 6, 8 ...
3�� ���: 3, 9, 27, ...
5�� ���: 0, 5, 5, ...
1. �� ��, 2�� 5�� ����̷��� 0���� �����߸� �Ѵ�!
2. 3�� ����� Ư¡�� ��� ���ڸ� �� ���ؼ� 3�� ����� �ȴٸ�, 3�� ����� ��
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main() {
	/*
	// �Է�
	int n, sum = 0, result = 0, count = 1;
	vector<int> a;
	bool is0 = false;
	cin >> n;
	while (n > 0) {
		if (n % 10 == 0) is0 = true;
		sum += (n % 10);
		a.push_back(n % 10);
		n /= 10;
	}
	cout << is0;
	cout << sum;
	if (sum / 3 && is0) {
		// ���� �������� ����
		sort(a.begin(), a.end());
		for (int i = 0; i < a.size(); i++) {
			result += a[i] * count;
			count *= 10;
		}
		cout << result;
	}

	else cout << "-1";
	*/
//}

// ������ ó���� �� ���� ���� - 10^5���� ���ڷ� �����Ǿ��ֱ� ������, ���ڿ��� ó���ؾ� �Ѵ�!
// ���� ���ڿ��� ó���ϴ� ���� �ξ� �ڵ尡 ��������
// �� ? ���ڿ� ��ü�� ������ ���� �ְ�, ���ڿ��� �κ��� ������ ���� �ֱ� ������

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	// ���ڿ����� �Է¹���
	string s;
	int sum = 0;
	cin >> s;
	sort(s.begin(), s.end());
	/* ���� ��� for��
	array�� ��Ҹ� �ݺ�!
	*/
	for (char c:s)
		sum += (c - '0');
	if (s[0] == '0' && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	else cout << "-1\n";
	return 0;
}