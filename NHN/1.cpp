#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Bug {
	string name;
	int cnt;
};

int main() {
	bool isTrue = false;
	char result = 'Y';
	int n;
	string buf;
	int buf2;
	int count = 0;// v.size()-1 초과되면 안됨
	vector<Bug> v;
	Bug b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		int j;
		for (j = 0; j < v.size(); j++)
			if (v[j].name == buf) {
				isTrue = true;
				break;
			}
		if (isTrue) v[j].cnt++;
		else {
			b.name = buf;
			b.cnt = 1;
			v.push_back(b);
		}
		isTrue = false;
	}
	isTrue = false;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++) {
			if (v[i].cnt == v[j].cnt) continue;
			else {
				if(isTrue==true) {
					result = 'N';
					break;
				}

				if (v[i].cnt - v[j].cnt == 1) {
					v[j].cnt += 1;
					isTrue = true;
				}
				else if (v[i].cnt - v[j].cnt == -1) {
					v[i].cnt += 1;
					isTrue = true;
				}
				else {
					result = 'N';
					break;
				}
			}
		}
		if (result == 'N') break;
	}

	cout << result << '\n';
	if (result=='Y' && isTrue) n += 1;
	cout << n << '\n';
	cout << v.size() << '\n';
	return 0;
}