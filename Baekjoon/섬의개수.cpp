#include <iostream>
#include <vector>
using namespace std;
//
//struct Way{
//	int x;
//	int y;
//};

int main() {
	int w, h;
	int buf = 0;
	//Way wa;
	int x[8][2] = { 
	{ -1, -1 },
	{ -1, 0 },
	{ -1, +1 },
	{ 0, -1 },
	{ 0, +1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, +1 },
	};
	vector<int> result;
	//vector<Way> ways;
	while (true) {
		buf = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int map[50][50];
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (map[i][j] == 1) {
					map[i][j]++;
					for (int k = 0; k < 8; k++) {
						if (i + x[k][0] >= 0 && i + x[k][0] < w && i + x[k][1] >= 0 && i + x[k][1] < h) {
							
						}
					}

				}
			}
		}

	}
	
}