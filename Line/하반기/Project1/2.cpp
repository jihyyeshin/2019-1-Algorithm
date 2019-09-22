#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int fac(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

int main() {
	vector<int> v;
	int len = 0;
	char buf;
	while (true) {
		cin.get(buf);
		if (buf == '\n') break;
		if (buf == ' ') continue;
		v.push_back(buf - '0');
		len++;
	}
	vector<int> indexC; // index로 조합 만드는 벡터
	vector<int> result(fac(len), 0); // 조합을 int형으로
	for (int i = 0; i < len; i++) {
		indexC.push_back(i + 1);
	}
	int index, count = 0;
	cin >> index;
	do {
		for (int i = 0; i < len; i++)
			result[count] += v[indexC[i] - 1] * int(pow(10, i));
		count++;
	} while (next_permutation(indexC.begin(), indexC.end()));

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end()); // 중복 제거

	string output = to_string(result[index - 1]);

	// 0 유지
	for (int i = 1; i < len; i++) {
		if (result[index - 1] / int(pow(10, len - i)) <= 0) {
			output.insert(0, "0");
		}
		else break;
	}
	cout << output << '\n';

}