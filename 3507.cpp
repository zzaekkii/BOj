#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
	cin >> N;
    
    // 최선의 코드 - 뽕뽑기님 블로그 https://codecollector.tistory.com/1305
    if(N>198) cout << 0; // 최대 2자리 수: 99 => 즉, 198 이내라면 가능.
	else cout << 99-(N-99)+1; // 순서에 상관없이 숫자들의 조합을 뽑는 경우의 수.
    
    /* 
    // 원래 풀이 - 브루트 포스
    int cnt = 0, i, j;
	for (i = 0; i <= 99; i++)
		for (j = 0; j <= 99; j++)
			if (i + j == n)cnt++;
	cout << cnt;
    */
}