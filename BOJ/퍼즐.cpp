/*
0 1 2
3 4 5
6 7 8

! ��Ž & ���
queue�� push pop

��� �������� �� check
�̵��� �Ұ����� ���?

������ �ִ� 4���� ĭ�� �� �� �ڸ��� ������ �� ����

�� �ڸ��� ������ �ڸ����� ����, ������ 4���� �³װ� �ִ��� Ȯ��

1. �� �ڸ��� ������ �ڸ�����:?

������ ��, �� �� �ִ� �ڸ�

0 : 13
1 : 024
2 : 15
3 : 046
4 : 1357
5 : 248
6 : 37
7 : 468
8 : 57
//*/
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	// �Է�
//	// ������ ���
//	string near[9] = { "134", "02345", "145", "01467", "01235678", "12478", "347", "34568", "457" };
//	int count = 0;
//	int zero, buf;
//
//	string input;
//	cin >> input;
//	// �ڸ� ã��
//	while(true){
//		if (input == "123456780") break;// �� ������ ���
//		zero = input.find("0")+1;
//
//		for (int i = 0; i < near[zero - 1].size(); i++) {
//			if (input[near[zero - 1][i]] == char(zero)) {
//				// ����ġ
//				buf = input[near[zero - 1][i]];
//				input[near[zero - 1][i]] = 0;
//				input[zero - 1] = buf;
//				break;
//			}
//		}
//		count++;
//	}
//
//
//	cout << count << '\n';
//}
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	
	//int a[3][3];
	string buf;
	string a;
	queue <int>way;
	int count = INT_MAX;//�ּҸ� ����
	string near[9] = { "13", "024", "15", "046", "1357", "248", "37", "468", "57" };

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> buf;
			a.append(buf);
		}
	// �Է� �Ϸ�

	/*
	1. zero�� ��ġ�� near[a.find("0")]
	2. near[i] queue�� ���� �� ������ �־����
	3. - 123456780�� �Ǹ� ������
		- queue�� ���̻� ������ ������

	*/

	//queue<int> a;
	cout << way.empty();
	if (count == INT_MAX) {// �� ���� �ڸ��� ã�� ������ ��
		cout << "-1\n";
		return 0;
	}
	else {// ������ �ּ��� ��
		cout << count << '\n';
		return 0;
	}

}