#include <string>
#include <vector>

using namespace std;
int col[15]; // 어차피 한 행에는 하나의 퀸밖에 올 수 없다.
// col(열)에 저장되는 정수값은 col[i]=j에서 (j, i)를 의미함.
int answer = 0;
int N;

bool promising(int i){
    for(int j=0;j<i;j++)// 한 행에 있거나 대각선에 있는 경우는 non_promising
        if(col[j]==col[i] || abs(col[i]-col[j])==(i-j)) return false;
    // 대각선에서 이와 같은 수식이 나오는 이유는, 행과 열의 크기 차이가 동일하면 대각선에 있는 것임
    return true;
}

void N_Queen(int i){
    if(i == N) answer++;
    else{
        for(int j = 0 ; j < N ; j++){
            col[i]=j;//모든 행의 값에 퀸을 놓았을 때
            if(promising(i)) N_Queen(i+1);// 유망한 경우만
        }
    }
}

int solution(int n) {
    N=n;
    N_Queen(0);
    return answer;
}