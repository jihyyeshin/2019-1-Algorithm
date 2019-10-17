#include <string>
#include <vector>

using namespace std;
int col[15]; // ������ �� �࿡�� �ϳ��� ���ۿ� �� �� ����.
// col(��)�� ����Ǵ� �������� col[i]=j���� (j, i)�� �ǹ���.
int answer = 0;
int N;

bool promising(int i){
    for(int j=0;j<i;j++)// �� �࿡ �ְų� �밢���� �ִ� ���� non_promising
        if(col[j]==col[i] || abs(col[i]-col[j])==(i-j)) return false;
    // �밢������ �̿� ���� ������ ������ ������, ��� ���� ũ�� ���̰� �����ϸ� �밢���� �ִ� ����
    return true;
}

void N_Queen(int i){
    if(i == N) answer++;
    else{
        for(int j = 0 ; j < N ; j++){
            col[i]=j;//��� ���� ���� ���� ������ ��
            if(promising(i)) N_Queen(i+1);// ������ ��츸
        }
    }
}

int solution(int n) {
    N=n;
    N_Queen(0);
    return answer;
}