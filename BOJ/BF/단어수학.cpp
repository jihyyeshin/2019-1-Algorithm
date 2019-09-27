/*
큰 숫자 M개만 넣어보면 됨
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
char alpha[256]; // 아스키 코드로, i의 값
int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
	int m = letters.size();
	int sum = 0;
	for (int i = 0; i < m; i++)
		alpha[letters[i]] = d[i];
	for (string s : a) {
		int now = 0;
		for (char x : s)
			now = now * 10 + alpha[x];
		sum += now; // 값을 계산하는 과정, 알파벳을 임의의 숫자로 넣고
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	vector<char> letters;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (char x : a[i]) // string을 char vector에 넣어주는 법
			letters.push_back(x);
	}
	// 중복 알파벳 제거
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
	int m = letters.size();
	vector<int> d;
	for (int  i = 9; i <9-m; i--)
	{
		d.push_back(i);
	}
	sort(d.begin(), d.end());
	int ans = 0;
	do {// 지금까지 구한 값보다 클 때 저장
		int now = calc(a, letters, d);
		if (ans < now)
			ans = now;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans << '\n';
	return 0;

}