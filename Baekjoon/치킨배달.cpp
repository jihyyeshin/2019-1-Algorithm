#include <iostream>
#include <algorithm>
using namespace std;

int chiway(int r1, int c1, int r2, int c2) {
	int buf = 0;
	if (r1 >= r2)
		buf = r1 - r2;
	else buf = r2 - r1;
	if (c1 >= c2)
		buf += c1 - c2;
	else buf += c2 - c1;
	return buf;
}

//넥스트 퍼뮤테이션

int main() {
	int n, m, buf;
	int h = 0, c = 0;
	int input[50][50];
	cin >> n >> m;
	int house[2][100];
	int chicken[2][100];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			if (input[i][j] == 1) {// 집개수
				house[0][h] = i;
				house[1][h] = j;
				h++;
			}
			else if (input[i][j] == 2) {// 치킨 개수
				chicken[0][c] = i;
				chicken[1][c] = j;
				c++;
			}
		}

	//int *way = new int[c];//거리를 저장해놓을 것
	//for (int i = 0; i < c; i++)
	//	way[i] = 0;
	int way[100][13] = { 0, };
	//int way = INT_MAX;
	cout << '\n';
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			buf = chiway(house[0][i], house[1][i], chicken[0][j], chicken[1][j]);
			way[i][j] = buf;
			cout << way[i][j] << " ";
		}
		cout << "\n";
	}
	buf = 0;
	int count = 0;
	int result = INT_MAX;
	for (int i = 0; i < h; i++) {
		for (int j = i; j < c; j++) {
			buf += way[i][j];
			if (result > buf) {
				result = buf;
			}
		}
	}

}