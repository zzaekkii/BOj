#include <bits/stdc++.h>
using namespace std;

int N;
int Tree[100001];
int tmp,ans;

int Gcd(int x,int y){
	if(!y)return x;
	else return Gcd(y,x%y);
}

int main(){                      
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> Tree[i];
	
	sort(Tree,Tree+N);
	
	for(int i=1;i<N;i++)
		Tree[i-1]=Tree[i]-Tree[i-1];
	
	tmp=Gcd(Tree[0],Tree[1]);
	for(int i=2;i<N-1;i++)
		tmp=Gcd(tmp,Tree[i]);
	
	for(int i=0;i<N-1;i++){
//		cout << Tree[i] << '/' << tmp << '\n'; 
		ans+=Tree[i]/tmp-1;
	}
		
	cout << ans;	
}
