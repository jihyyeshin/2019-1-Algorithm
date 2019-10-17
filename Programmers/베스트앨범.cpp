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
	vector<mu> mTotal;// ��ü �� ����
	vector<string> gBuf;// �帣 �����
	for (int i = 0; i<genres.size(); i++) {
		if (find(gBuf.begin(), gBuf.end(), genres[i]) == gBuf.end()) {// ���ٸ�
			mu m;
			gBuf.push_back(genres[i]);
			m.name = genres[i];
			m.ply.push_back(make_pair(plays[i], i));
			mTotal.push_back(m);
		}
		else { // �ִٸ�
			auto it = find(gBuf.begin(), gBuf.end(), genres[i]);
			int index = distance(gBuf.begin(), it); // distance ����ؼ� indexã��
			mTotal[index].ply.push_back(make_pair(plays[i], i));
		}
	}
	// ��ü �� ����
	vector< pair<int, int> > count;
	int buf = 0;
	for (int i = 0; i<mTotal.size(); i++) {
		for (int j = 0; j<mTotal[i].ply.size(); j++) {
			buf += mTotal[i].ply[j].first;
		}
		count.push_back(make_pair(buf, i));
		buf = 0;
	}
	// ����
	sort(count.begin(), count.end());
	for (int i = 0; i<mTotal.size(); i++) {
		sort(mTotal[i].ply.begin(), mTotal[i].ply.end());

	}

	for (int i = count.size() - 1; i >= 0; i--) {
		buf = mTotal[count[i].second].ply.size();
		if (buf <= 1) {// �Ѱ� �ۿ� ���� ��
			answer.push_back(mTotal[count[i].second].ply[0].second);
		}
		else { // ���� ���� �� idx�� ���� ������ ���� answer�� push_back �ؾ� �ϱ� ������, �ڵ� �߰�.
			// sort�� ������������ �� �� ������ �ʿ� ���� �ڵ�,,
			if (mTotal[count[i].second].ply[buf - 1].first == mTotal[count[i].second].ply[buf - 2].first) {// ���� ������
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