#include <bits/stdc++.h>
using namespace std;

int N,X;
int Arr[250001];
int mx,cnt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> X;
	
	for(int i=1;i<=N;i++){
		cin >> Arr[i];
        Arr[i]+=Arr[i-1];
	}
	
	for(int i=X;i<=N;i++){
		if(mx<Arr[i]-Arr[i-X]){
			mx=Arr[i]-Arr[i-X];
			cnt=1;
		}
		else if(mx==Arr[i]-Arr[i-X])cnt++;
	}
	
	if(!mx)cout << "SAD";
	else cout << mx << '\n' << cnt;
}
