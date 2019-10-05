#include <iostream>
using namespace std;

int main() {
	int n, m, l, myTurn = 1;
	bool isEnd = false;
	cin >> n >> m >> l;
	int result = 0;
	int cnt[1003] = { 0, };
	cnt[1] = 1;
	while (true) {
		if (cnt[myTurn] % 2 == 1) {//홀수
			if (myTurn + l <= n)
				myTurn = myTurn + l;
			else
				myTurn = l - (n - myTurn);
		}
		else if (cnt[myTurn] % 2 == 0) {//짝수
			if (myTurn - l > 0)
				myTurn = myTurn - l;
			else
				myTurn = n - l + myTurn;
		}

		cnt[myTurn]++;
		result++;

		// m번이 되었는지 검사
		for (int i = 0; i <= n; i++) {
			if (cnt[i] == m)
				isEnd = true;
		}
		if (isEnd == true) {
			cout << result << '\n';
			return 0;
		}
	}	
}