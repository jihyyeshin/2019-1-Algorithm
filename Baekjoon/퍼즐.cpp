/*
0 1 2
3 4 5
6 7 8

0 : 1,3,4 
1 : 0, 2, 3, 4, 5
2: 1, 4, 5
3 : 0, 1, 4, 6, 7
4 : ����
5 : 12478
6:347
7:34568
8:457

��� �������� �� check
�̵��� �Ұ����� ���?

������ �ִ� 4���� ĭ�� �� �� �ڸ��� ������ �� ����

�� �ڸ��� ������ �ڸ����� ����, ������ 4���� �³װ� �ִ��� Ȯ��

1. �� �ڸ��� ������ �ڸ�����:?

*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	// �Է�
	// ������ ���
	string near[9] = { "134", "02345", "145", "01467", "01235678", "12478", "347", "34568", "457" };
	int count = 0;
	int zero, buf;

	string input;
	cin >> input;
	// �ڸ� ã��
	while(true){
		if (input == "123456780") break;// �� ������ ���
		zero = input.find("0")+1;

		for (int i = 0; i < near[zero - 1].size(); i++) {
			if (input[near[zero - 1][i]] == char(zero)) {
				// ����ġ
				buf = input[near[zero - 1][i]];
				input[near[zero - 1][i]] = 0;
				input[zero - 1] = buf;
				break;
			}
		}
		count++;
	}


	cout << count << '\n';
}