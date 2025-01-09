// 21919번 소수 최소 공배수 - 실버3 / #수학
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  if(!b)return a;
  return gcd(b,a%b);
}
 
ll lcd(ll a, ll b){
  return a/gcd(a,b)*b;
}

int N, T;
bool notPrime[1'000'001];
vector<int> V;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=2;i<=1'000'000;i++)
		for(int j=i+i;j<=1'000'000;j+=i)
			notPrime[j]=1;
	
	for(int i=0;i<N;i++){
		cin >> T;
		if(!notPrime[T])V.emplace_back(T);
	}
	
	if(V.empty())cout << -1;
	else{
		ll ans=V[0];
		int l=V.size();
		for(int i=1;i<l;i++)
			ans=lcd(ans,V[i]);
		cout << ans;
	}
}
