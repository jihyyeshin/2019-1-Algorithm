
#include <vector>
#include <iostream>
#include <string>
using namespace std;

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

/*
�߸��� ��
- 1, 2, 3, 4�� ��ϰ� ȸ���ϴ� ���� ������ �޼ҵ�� �����ϴ� ���� ����.
���� ���������� !
*/


//int main() {
//	string t1;
//	string t2;
//	string t3;
//	string t4;
//	int result = 0;
//	vector<bool> isDif;
//	//vector<int, int> change;
//	int n, buf, buf2;
//	// �Է� �� �ʱ�ȭ
//	cin >> t1 >> t2 >> t3 >> t4;
//	cin >> n;
//	int *changeNum = new int[n];// ȸ���� ��
//	int *changeR = new int[n];// ȸ�� ����
//	for (int i = 0; i < n; i++) {
//		cin >> changeNum[i] >> changeR[i];
//	}
//	for (int i = 0; i < 3; i++)
//		isDif.push_back(false);
//	// �Է� �Ϸ�
//	for (int i = 0; i < n; i++) {
//		// �ٸ� �ֵ��� true�� ������
//		if (t1[2] != t2[6]) isDif[0] = true;
//		else if (t2[2] != t3[6]) isDif[1] = true;
//		else if (t3[2] != t4[6]) isDif[2] = true;
//		// �Է¹��� ���׿� ���� ȸ��
//		if (changeNum[i] == 1) { // num=1
//			if (changeR[i] == 1) { //�ð�
//				t1 = sChange(t1);
//				if (isDif[0]) {
//					t2 = bChange(t2);
//					if (isDif[1]) {
//						t3 = sChange(t3);
//						if (isDif[2]) t4 = bChange(t4);
//					}
//				}
//			}
//			else { // �ݽð�
//				t1 = bChange(t1);
//				if (isDif[0]) {
//					t2 = sChange(t2);
//					if (isDif[1]) {
//						t3 = bChange(t3);
//						if (isDif[2]) t4 = sChange(t4);
//					}
//				}
//			}
//		}
//		else if (changeNum[i] == 2) { // num=2
//			if (changeR[i] == 1) { //�ð�
//				t2 = sChange(t2);
//				if (isDif[0]) 
//					t1 = bChange(t1);
//				if (isDif[1]) {
//					t3 = bChange(t3);
//					if (isDif[2])
//						t4 = sChange(t4);
//				}
//			}
//			else { // �ݽð�
//				t2 = bChange(t2);
//				if (isDif[0])
//					t1 = sChange(t1);
//				if (isDif[1]) {
//					t3 = sChange(t3);
//					if (isDif[2])
//						t4 = bChange(t4);
//				}
//			}
//		}
//		else if (changeNum[i] == 3) { // num=3
//			if (changeR[i] == 1) { //�ð�
//				t3 = sChange(t3);
//				if (isDif[2])
//					t4 = bChange(t4);
//				if (isDif[1]) {
//					t2 = bChange(t2);
//					if(isDif[0]) t1 = sChange(t1);
//				}
//			}
//			else { // �ݽð�
//				t3 = bChange(t3);
//				if (isDif[2])
//					t4 = sChange(t4);
//				if (isDif[1]) {
//					t2 = sChange(t2);
//					if (isDif[0]) t1 = bChange(t1);
//				}
//			}
//		}
//		else { // num=4
//			if (changeR[i] == 1) { //�ð�
//				t4 = sChange(t4);
//				if (isDif[2]) {
//					t3 = bChange(t3);
//					if (isDif[1]) {
//						t2 = sChange(t2);
//						if(isDif[0]) t1 = bChange(t1);
//					}
//				}
//			}
//			else { // �ݽð�
//				t4 = bChange(t4);
//				if (isDif[2]) {
//					t3 = sChange(t3);
//					if (isDif[1]) {
//						t2 = bChange(t2);
//						if (isDif[0]) t1 = sChange(t1);
//					}
//				}
//			}
//		}
//
//		for (int i = 0; i < 3; i++)
//			isDif[i] = false;// �ʱ�ȭ
//	}
//
//	if (t1[0] == '1') result += 1;
//	if (t2[0] == '1') result += 2;
//	if (t3[0] == '1') result += 4;
//	if (t4[0] == '1') result += 8;
//
//	cout << result << '\n';
//	return 0;
//}


int main() {
	string t1;
	string t2;
	string t3;
	string t4;
	int result = 0;
	vector<bool> isDif;
	int n, buf, buf2;
	// �Է� �� �ʱ�ȭ
	cin >> t1 >> t2 >> t3 >> t4;
	cin >> n;
	int *changeNum = new int[n];// ȸ���� ��
	int *changeR = new int[n];// ȸ�� ����
	for (int i = 0; i < n; i++) {
		cin >> changeNum[i] >> changeR[i];
	}
	for (int i = 0; i < 3; i++)
		isDif.push_back(false);
	// �Է� �Ϸ�

	return 0;
}