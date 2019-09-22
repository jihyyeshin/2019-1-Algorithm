#include <iostream>
#include <string>
using namespace std;
int main() {
	string resultS, s;
	int num = 1;
	int result = INT_MAX, buf, nResult;
	cin >> s;
	int i, j;
	for (int k = 1; k < s.size(); k++) {
		for (i = 0; i < s.size(); i += k) {
			buf = i;
			for (j = i + 1; j < s.size(); j += k) {
				if (s[buf] - s[j] == 0) {
					num++;
					i = j;
				}
				else {
					if (num != 1) {
						resultS += to_string(num);
						resultS += s[buf];
					}
					else resultS += s[buf];
					num = 1;
					break;
				}
			}
		}
		if (num != 1) {
			resultS += to_string(num);
			resultS += s[buf];
		}
		else resultS += s[buf];
		nResult = resultS.size();
		cout << "°á°ú " << resultS << "\n";
		if (nResult < result)
			result = nResult;
		resultS = "";
	}
	cout << result << "\n";
}

