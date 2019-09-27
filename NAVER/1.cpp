#include <iostream>
#include <vector>
#include <string>
using namespace std;
int solution(vector<string> emails);

int main() {
	int count = 0;
	string input;
	vector<string> emails;
	//cin >> input; //ют╥б
	for (int i = 0; i < 4; i++) {
		cin >> input;
		emails.push_back(input);
	}
	cout << "solution is.."<<solution(emails) << '\n';
}

int solution(vector<string> emails) {
	string buf;
	bool isEmail = true;
	int answer = 0;
	int ea=0 , ja=0;
	for (int i = emails.size()-1; i >=0; i--) {
		isEmail = true;
		string buf = emails.at(i);
		if (buf.size() < 7) continue;
		emails.pop_back();

		string buf2="....";
		for (int j = 0; j < 4; j++) {
			buf2[j]=buf[buf.size() - j - 1];
		}
		
		/*if (buf2.find(".com") >= 0)
			ja = buf.size() - 4;
		else if (buf2.find(".net")>=0)
			ja = buf.size() - 4;
		else if (buf2.find(".org")>=0)
			ja = buf.size() - 4;*/
		if (buf2.find("moc.")!=-1 || buf2.find("ten.") != -1 || buf2.find("gro.") != -1)
			ja = buf.size() - 4;
		else continue;

		for (int j = ja - 1; j >= 0; j--) {
			if (buf[j] == '@') {
				ea = j;
				break;
			}
		}

		for (int j = 0; j < ea; j++) {
			if (buf[j] == 46 || (buf[j] >= 97 && buf[j] <= 122)) {}
			else {
				isEmail = false;
				break;
			}
		}
		for (int j = ea + 1; j < ja; j++) {
			if (buf[j] >= 97 && buf[j] <= 122) {}
			else {
				isEmail = false;
				break;
			}
		}

		if (isEmail == false) continue;

		answer++;
	}

	return answer;
}