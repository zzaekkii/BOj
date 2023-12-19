#include <bits/stdc++.h>
using namespace std;
int N;
int coin[100001]={0,0,1,0,2,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=6;i<=N;i++){
    	if(!coin[i-2]&&!coin[i-5])coin[i]=0;
    	else if(!coin[i-2]||!coin[i-5])coin[i]=max(coin[i-2],coin[i-5])+1;
    	else coin[i]=min(coin[i-2],coin[i-5])+1;
	}
	if(!coin[N])cout << -1;
	else cout << coin[N];
}
