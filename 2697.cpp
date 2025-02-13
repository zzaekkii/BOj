// 2697번 다음수 구하기 - 실버2 / 그리디 
#include <bits/stdc++.h>
using namespace std;

int T;
string S;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	
	while(T--){
		cin >> S;
		
		int l=S.length();
		int idx=0;
		
		for(int i=l-1;i>0;i--)
			if(S[i]>S[i-1]){
				idx=i;
				break;
			}
		
		if(idx){
			char mn='9'+1;
			int target=0;
			
			for(int i=idx;i<l;i++)
				if(S[idx-1]<S[i]&&mn>S[i]){
					mn=S[i];
					target=i;
				}
			
			swap(S[idx-1],S[target]);
			
			string s1=S.substr(0,idx), s2=S.substr(idx);
			sort(s2.begin(),s2.end());
			
			cout << s1 << s2 << '\n';
		}
		else cout << "BIGGEST\n";
	}
}
