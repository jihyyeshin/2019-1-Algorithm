#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int w=0, h=0, N;
	cin >> N;
	
	int buf= sqrt(N);

	for (int i = buf; i >0; i--) {
		if (N%i == 0) {
			w = i;
			h = N / i;
			break;
		}
	}
	cout << abs(w - h);
	return 0;
}