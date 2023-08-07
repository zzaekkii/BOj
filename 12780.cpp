#include <bits/stdc++.h>
using namespace std;
string H, N;
int cnt;
bool f;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> H >> N;
	int i, j, h=H.size(), n=N.size();
	
	for(i=0;i<h-n+1;i++){
		f=1;
		if(H[i]==N[0]){
			for(j=0;j<n;j++)
				if(H[i+j]!=N[j]){
					f=0;
					break;
				}
			if(f)cnt++;
		}
	}
	cout << cnt;
}
