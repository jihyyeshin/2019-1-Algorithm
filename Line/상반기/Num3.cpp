#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int size1, size2, i;
	cin >> size1;
	string *arr1 = new string[size1+2];
	int *id1 = new int[size1 + 2];


	for (i = 0; i < size1; i++) {
		cin >> arr1[i];
	}
	for (i = 1; i < size1; i++) {
		//arr[1].
	}
	cin >> size2;
	string *arr2 = new string[size2 + 2];
	int *id2 = new int[size2 + 2];
	for (int i = 0; i < size2; i++) {
		cin >> arr2[i];

	}

	return 0;
}
