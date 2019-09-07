/*
20���̴�? 1���� �Ѵ� ���, for��, �迭 ��� �Ұ����ϴٴ� ��
: �� �� ������ ���� �ذ�Ǵ� ��찡 ��κ� !!!

height�� �������� �ؼ� height�� �þ �� ���� �湮�� �� �ִ� ĭ�� ����

- height=1
�̵��� �� ���� ������ 1
- height=2
��� �̵������ �� �� ���� ������ �ִ밡 4��
�׸���, ���������� �� �� 
width=3 �̸� 2ĭ
width=5 �̸� 3ĭ
�̷��� �þ�� ������ (width+1)/2ĭ
���� min(4, (width+1)/2)
- height>=3
1) width >=7
��� �̵� ����� �� �� �� �ִ� ����̹Ƿ�, ����ؼ� �� ĭ���� �̵� ����
�ϴ� ��� �̵� ����� �� ���� ��, 7ĭ �� 5ĭ�� �� �� �ְ�,
�� �ķδ� �� ĭ�� ������ �� �� �ֱ� ������
width-2
2) width <7
��� �̵� ����� �� �� �� ���� ������,
min(4, width)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int height, width;
	cin >> height >> width;
	if (height == 1) {
		cout << 1;
	}
	else if (height == 2) {
		cout << min(4, (width + 1) / 2);
	}
	else if (height >= 3) {
		if (width >= 7)
			cout << width - 2;
		else
			cout << min(4, width);
	}
	cout << '\n';
	return 0;
}