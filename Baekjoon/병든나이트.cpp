/*
20억이다? 1억을 넘는 경우, for문, 배열 모두 불가능하다는 뜻
: 이 때 수식을 통해 해결되는 경우가 대부분 !!!

height를 기준으로 해서 height가 늘어날 때 마다 방문할 수 있는 칸을 센다

- height=1
이동할 수 없기 때문에 1
- height=2
모든 이동방법을 쓸 수 없기 때문에 최대가 4임
그리고, 오른쪽으로 갈 때 
width=3 이면 2칸
width=5 이면 3칸
이렇게 늘어나기 때문에 (width+1)/2칸
따라서 min(4, (width+1)/2)
- height>=3
1) width >=7
모든 이동 방법을 다 쓸 수 있는 경우이므로, 계속해서 옆 칸으로 이동 가능
일단 모든 이동 방법을 다 썼을 때, 7칸 중 5칸을 갈 수 있고,
그 후로는 한 칸씩 옆으로 갈 수 있기 때문에
width-2
2) width <7
모든 이동 방법을 다 쓸 수 없기 때문에,
min(4, width)
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int height, width;
	cin >> height >> width;
	if (height == 1) {
		cout << 1;
	}
	else if (height == 2) {
		cout << min(4, (width + 1) / 2);
	}
	else if (height >= 3) {
		if (width >= 7)
			cout << width - 2;
		else
			cout << min(4, width);
	}
	cout << '\n';
	return 0;
}