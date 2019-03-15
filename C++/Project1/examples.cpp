#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main() {

	cout << "\nthis is vector" << endl;

	vector<int> v;
	v.reserve(8);//벡터 메모리 공간 8 예약 할당

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;

	cout << "size: " << v.size() << endl
		<< "capacity: " << v.capacity() << endl
		<< "max_size: " << v.max_size() << endl;

	v.resize(10);


	cout << "\nthis is stack" << endl;

	stack<int> s;

	s.push(3);
	s.push(2);

	cout << "top element: " << s.top() << "\n";

	s.pop();

	cout << "stack size" << s.size() << "\n";

	cout << "Is it empty?:" << (s.empty() ? "Yes" : "No") << "\n";
	
	cout << "\nthis is queue" << endl;
	queue<int> q;

	q.push(10);
	cout << q.front();
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	cout << "\nthis is math" << endl;
	cout << pow(2, 3);

	cout << "\nthis is map" << endl;
	map<string, int> m;//key와 value를 pair형태로 선언한다.

	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));

	m.erase("a");
	m.erase(m.find("b"));

	cout << "\nthis is algorithm" << endl;

	int a[100];
	sort(a, a + 100);

	vector<int> b(100);

	sort(b.begin(), b.end());

	struct Point {
		int x;
		int y;
	};
	bool cmp(const Point &p1, const Point &p2) {
		if (p1.x < p2.x) {
			return true;

		}
	}
}