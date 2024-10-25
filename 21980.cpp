// 21980번 비슷한 번호 - 실버2 / 문자열, 해시맵, 구현, 조합론.
#include <bits/stdc++.h>
using namespace std;

int T,N,K;
string S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> N >> K;
    	
		map<string,int> M[21]; // 대문자 개수만큼 맵이 있음 + 케이스마다 초기화.
		int ans=0;
    	for(int i=0;i<N;i++){
    		int up=0; // 대문자 개수 췌~크.
    		cin >> S;
    		
    		for(int j=0;S[j];j++){
    			// 1. 대문자 개수 체크하고.
    			if(S[j]>='A'&&S[j]<='Z')up++;
    			// 2. 대문자로 변환하고. 
    			S[j]=toupper(S[j]);
			  }
			  // 3. 대문자화된 문자열을 정렬. 
			  sort(S.begin(),S.end());
			  // 4. 대문자 개수 인덱스 맵에 문자열 정렬. 
			  M[up][S]++;
    	}

      // 5. 개수별 맵 훑어보면서.
    	for(int i=0;i<=20;i++)
    		for(auto a: M[i])
          // 6. 비슷한 문자열 개수가 2개 이상이라면.
    			if(a.second>=2)
            // 7. nP2로 짝 개수를 총 합에 더하기.
    				ans+=a.second*(a.second-1)/2;
		
		cout << ans << '\n';
	}
}
