/*
0 1 2
3 4 5
6 7 8

! 완탐 & 재귀
queue로 push pop

방금 움직였던 것 check
이동이 불가능한 경우?

인접해 있는 4개의 칸이 다 그 자리를 차지할 수 있음

그 자리가 누구의 자리인지 보고, 인접한 4개에 걔네가 있는지 확인

1. 내 자리가 누구의 자리인지:?

인접한 것, 갈 수 있는 자리

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
//	// 입력
//	// 인접한 경우
//	string near[9] = { "134", "02345", "145", "01467", "01235678", "12478", "347", "34568", "457" };
//	int count = 0;
//	int zero, buf;
//
//	string input;
//	cin >> input;
//	// 자리 찾기
//	while(true){
//		if (input == "123456780") break;// 다 수정한 경우
//		zero = input.find("0")+1;
//
//		for (int i = 0; i < near[zero - 1].size(); i++) {
//			if (input[near[zero - 1][i]] == char(zero)) {
//				// 스위치
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
	int count = INT_MAX;//최소를 저장
	string near[9] = { "13", "024", "15", "046", "1357", "248", "37", "468", "57" };

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> buf;
			a.append(buf);
		}
	// 입력 완료

	/*
	1. zero의 위치를 near[a.find("0")]
	2. near[i] queue에 가야 할 방향을 넣어놓자
	3. - 123456780이 되면 끝내기
		- queue에 더이상 없으면 끝내기

	*/

	//queue<int> a;
	cout << way.empty();
	if (count == INT_MAX) {// 한 번도 자리를 찾지 못했을 때
		cout << "-1\n";
		return 0;
	}
	else {// 나머지 최소일 때
		cout << count << '\n';
		return 0;
	}

}