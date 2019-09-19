/*
0 1 2
3 4 5
6 7 8

0 : 1,3,4 
1 : 0, 2, 3, 4, 5
2: 1, 4, 5
3 : 0, 1, 4, 6, 7
4 : 전부
5 : 12478
6:347
7:34568
8:457

방금 움직였던 것 check
이동이 불가능한 경우?

인접해 있는 4개의 칸이 다 그 자리를 차지할 수 있음

그 자리가 누구의 자리인지 보고, 인접한 4개에 걔네가 있는지 확인

1. 내 자리가 누구의 자리인지:?

*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	// 입력
	// 인접한 경우
	string near[9] = { "134", "02345", "145", "01467", "01235678", "12478", "347", "34568", "457" };
	int count = 0;
	int zero, buf;

	string input;
	cin >> input;
	// 자리 찾기
	while(true){
		if (input == "123456780") break;// 다 수정한 경우
		zero = input.find("0")+1;

		for (int i = 0; i < near[zero - 1].size(); i++) {
			if (input[near[zero - 1][i]] == char(zero)) {
				// 스위치
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