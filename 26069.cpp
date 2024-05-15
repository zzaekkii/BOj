#include <bits/stdc++.h>
using namespace std;

int N;
string A,B;
map<string,int> M;
bool rb[2001];

int cnt,ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> A >> B;
		
		if(M.find(A)==M.end())
			M.insert({A,cnt++});
		if(M.find(B)==M.end())
			M.insert({B,cnt++});
		
		if(A=="ChongChong")rb[M[A]]=1;
		if(B=="ChongChong")rb[M[B]]=1;
		
		if(rb[M[A]]||rb[M[B]])
			rb[M[A]]=rb[M[B]]=1;
	}
	
	for(int i=0;i<cnt;i++)
		ans+=rb[i];
		
	cout << ans;
}
