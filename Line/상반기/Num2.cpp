#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int str_len = 0;
	int stlen = 0;
	int inlen = 0;
	int i, j;
	string str;
	string result;
	cin >> str;

	for (i = 0; i < str.length(); i++) {
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			str_len++;
		else break;
	}

	inlen = str.length() - str_len;

	if (str_len == str.length()) {
		cout << "error";
		return 0;
	}

	j = str_len;

	for (i = 0; i < str_len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			result.append(1, str[i]);
			stlen++;
			if (str_len != i + 1) {
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
					i = i + 1;
					result.append(1, str[i]);
				}
			}
			if (str.length() <= j) {
				cout << "error";
				return 0;
			}
			if (str.length() != j && str[j + 1] == '0' && str[j] == '1') {
				result.append(1, str[j]);
				j += 1;
				result.append(1, str[j]);
				j += 1; 
				inlen--;
			}
			else if (str[j] != '1') {
				result.append(1, str[j]);
				j += 1;
			}
			else if (str[j] == '1') {
				j += 1; 
			}
		}
	}
	if (inlen!=stlen)
		cout << "error";
	else cout << result;

}
