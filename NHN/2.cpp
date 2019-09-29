#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Num[101] = { 0, };

int main() {
	int n, index = 0, totalcnt = 0;
	bool  flag=false;
	string bufstr;
	int buf;
	vector<int> returnV, v, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bufstr;
		if (bufstr == "enqueue") {
			cin >> buf;
			v.push_back(buf);
			Num[buf] ++;
		}
		else if (bufstr == "dequeue") {
			if (v.size() <= 0) return -1;

			for (int j = 0; j < 100; j++)
			{
				if (Num[j] > totalcnt) {
					totalcnt = Num[j];
					index = j;
				}
			}
			returnV.push_back(index);
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == index) {
					if (flag = false) {
						flag = true;
						continue;
					}
				}
				tmp.push_back(v[j]);
			}
			buf = v.size();
			v.resize(buf - 1);
			//copy
			for (int j = 0; j < v.size(); j++) {
				v[j] = tmp[j];
			}
			Num[index]--;

		}
		flag = false;
		index = 0;
		totalcnt = 0;
	}
	//cout << buf;
	for (int i = 0; i < returnV.size(); i++)
		cout << returnV[i] << ' ';
	return 0;
}