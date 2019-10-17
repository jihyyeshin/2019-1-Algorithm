#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct mu {
	string name;
	vector< pair<int, int> > ply;// first: ply, second: idx
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<mu> mTotal;// 전체 값 저장
	vector<string> gBuf;// 장르 저장소
	for (int i = 0; i<genres.size(); i++) {
		if (find(gBuf.begin(), gBuf.end(), genres[i]) == gBuf.end()) {// 없다면
			mu m;
			gBuf.push_back(genres[i]);
			m.name = genres[i];
			m.ply.push_back(make_pair(plays[i], i));
			mTotal.push_back(m);
		}
		else { // 있다면
			auto it = find(gBuf.begin(), gBuf.end(), genres[i]);
			int index = distance(gBuf.begin(), it); // distance 사용해서 index찾음
			mTotal[index].ply.push_back(make_pair(plays[i], i));
		}
	}
	// 전체 수 세기
	vector< pair<int, int> > count;
	int buf = 0;
	for (int i = 0; i<mTotal.size(); i++) {
		for (int j = 0; j<mTotal[i].ply.size(); j++) {
			buf += mTotal[i].ply[j].first;
		}
		count.push_back(make_pair(buf, i));
		buf = 0;
	}
	// 정렬
	sort(count.begin(), count.end());
	for (int i = 0; i<mTotal.size(); i++) {
		sort(mTotal[i].ply.begin(), mTotal[i].ply.end());

	}

	for (int i = count.size() - 1; i >= 0; i--) {
		buf = mTotal[count[i].second].ply.size();
		if (buf <= 1) {// 한곡 밖에 없을 때
			answer.push_back(mTotal[count[i].second].ply[0].second);
		}
		else { // 값이 같을 때 idx가 낮은 순서로 먼저 answer에 push_back 해야 하기 때문에, 코드 추가.
			// sort를 내림차순으로 할 수 있으면 필요 없는 코드,,
			if (mTotal[count[i].second].ply[buf - 1].first == mTotal[count[i].second].ply[buf - 2].first) {// 값이 같으면
				if (mTotal[count[i].second].ply[buf - 1].second > mTotal[count[i].second].ply[buf - 2].second) {
					answer.push_back(mTotal[count[i].second].ply[buf - 2].second);
					answer.push_back(mTotal[count[i].second].ply[buf - 1].second);
				}
				else {
					answer.push_back(mTotal[count[i].second].ply[buf - 1].second);
					answer.push_back(mTotal[count[i].second].ply[buf - 2].second);
				}
			}
			else {
				for (int j = buf - 1; j >= buf - 2; j--) {
					answer.push_back(mTotal[count[i].second].ply[j].second);
				}
			}
		}
	}
	return answer;
}