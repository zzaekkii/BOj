#include <bits/stdc++.h>
using namespace std;

int N;
int S[200001];
int ex[10];
int ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> S[i];
	
	for(int st=0,en=0,cnt=0;en<N;en++){
		ex[S[en]]++;
		
		if(ex[S[en]]==1)cnt++;
		
		while(cnt>2){
			if(!(--ex[S[st]]))cnt--;
			st++;
		}
		
		ans=max(ans,en-st+1);
	}
	
	cout << ans;
}
