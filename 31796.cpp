// 31796번 한빛미디어 (Easy) - 실버4 / #그리디 
#include <bits/stdc++.h>
using namespace std;

int N;
int S[100001];
int fr=1, ba=1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> S[i];
	
	sort(S,S+N);
	
	int f_mn=S[0];
	for(int i=1;i<N;i++)
		if(f_mn*2<=S[i]){
			f_mn=S[i];
			fr++;
		}
	
	int b_mx=S[N-1];
	for(int i=N-2;i>=0;i--)
		if(b_mx>=S[i]*2){
			b_mx=S[i];
			ba++;
		}
	
	cout << min(fr,ba);
}
