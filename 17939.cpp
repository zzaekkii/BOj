#include <bits/stdc++.h>
using namespace std;

int N;
int co[100001];
int ans,mx;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> co[i];
    	
    mx=co[N-1];
    
    for(int i=N-2;i>=0;i--)
    	if(co[i]>mx)mx=co[i];
    	else ans+=mx-co[i];
    	
    cout << ans;
}
