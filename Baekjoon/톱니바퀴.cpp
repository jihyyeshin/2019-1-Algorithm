#include <vector>
#include <iostream>
#include <string>
using namespace std;

void changeOne(string* t, int changeR, bool* checked);
void changeTwo(string* t, int changeR, bool* checked);
void changeThr(string* t, int changeR, bool* checked);
void changeFr(string* t, int changeR, bool* checked);

string sChange(string a) {// �ð�������� ȸ��
	string result = a;
	result[0] = a[a.size() - 1];
	for (int i = 0; i < a.size() - 1; i++) {
		result[i + 1] = a[i];
	}
	return result;
}
string bChange(string a) {// �ݽð�������� ȸ��
	string result = a;
	result[a.size() - 1] = a[0];
	for (int i = 0; i < a.size() - 1; i++) {
		result[i] = a[i + 1];
	}
	return result;
}

void changeOne(string* t, int changeR, bool* checked) {
	if (checked[0] == false) {
		checked[0] = 1;
		if (changeR == 1) {// �ð����
			if (t[0][2] != t[1][6])
				changeTwo(t, -1, checked);
			t[0] = sChange(t[0]);

		}
		else {// �ݽð�
			if (t[0][2] != t[1][6])
				changeTwo(t, 1, checked);
			t[0] = bChange(t[0]);
		}
	}
}

void changeTwo(string* t, int changeR, bool* checked) {
	if (checked[1] == false) {
		checked[1] = 1;
		if (changeR == 1) {
			if (t[0][2] != t[1][6])
				changeOne(t, -1, checked);
			if (t[1][2] != t[2][6])
				changeThr(t, -1, checked);
			t[1] = sChange(t[1]);
		}
		else {
			if (t[0][2] != t[1][6])
				changeOne(t, 1, checked);
			if (t[1][2] != t[2][6])
				changeThr(t, 1, checked);
			t[1] =bChange(t[1]);
		}
	}
}

void changeThr(string* t, int changeR, bool* checked) {
	if (checked[2] == false) {
		checked[2] = 1;

		if (changeR == 1) {
			if (t[2][2] != t[3][6])
				changeFr(t, -1, checked);
			if (t[1][2] != t[2][6])
				changeTwo(t, -1, checked);
			t[2] = sChange(t[2]);
		}
		else {
			if (t[2][2] != t[3][6])
				changeFr(t, 1, checked);
			if (t[1][2] != t[2][6])
				changeTwo(t, 1, checked);
			t[2] = bChange(t[2]);
		}
	}
}

void changeFr(string* t, int changeR, bool* checked) {
	if (checked[3] == false) {
		checked[3] = 1;
		if (changeR == 1) {// �ð����
			if (t[2][2] != t[3][6])
				changeThr(t, -1, checked);
			t[3] = sChange(t[3]);

		}
		else {// �ݽð�
			if (t[2][2] != t[3][6])
				changeThr(t, 1, checked);
			t[3] = bChange(t[3]);
		}
	}
}

int main() {
	string t[4];
	int result = 0;
	bool checked[4] = { 0, };//�̹� �� �� ���Ҵ��� Ȯ���ϱ� ���� bool
	int n, buf, buf2;
	// �Է� �� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
		cin >> t[i];
	cin >> n;
	int *changeNum = new int[n];// ȸ���� ��
	int *changeR = new int[n];// ȸ�� ����
	for (int i = 0; i < n; i++) {
		cin >> changeNum[i] >> changeR[i];
	}

	for (int i = 0; i < n; i++) // ȸ��
	{
		if (changeNum[i] == 1) {
			changeOne(t, changeR[i], checked);
		}
		else if (changeNum[i] == 2) {
			changeTwo(t, changeR[i], checked);
		}
		else if (changeNum[i] == 3) {
			changeThr(t, changeR[i], checked);
		}
		else {// changeNum==4
			changeFr(t, changeR[i], checked);
		}

		// �ʱ�ȭ
		for (int j = 0; j < 4; j++)
			checked[j] = 0;
	}

	if (t[0][0] == '1') result += 1;
	if (t[1][0] == '1') result += 2;
	if (t[2][0] == '1') result += 4;
	if (t[3][0] == '1') result += 8;

	cout << result << '\n';
	return 0;
}
