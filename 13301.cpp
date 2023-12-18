#include <bits/stdc++.h>
using namespace std;
int N;
long long t[81]={0,1,1,2};
long long ans=4;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N!=1){
      for(int i=4;i<=N;i++) t[i]=t[i-1]+t[i-2];
      ans=2*(t[N]+2*t[N-1]+t[N-2]);
	  }
    cout << ans;
}
