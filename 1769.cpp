#include <bits/stdc++.h>
using namespace std;

string X;
int sum,ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> X;
	
	for(int i=0;X[i];i++)
		sum+=X[i]-48;
	
	if(sum/10)
		while(1){
			ans++;
			if(!(sum/10))break;
			int tmp=0;
			while(sum>0){
				tmp+=sum%10;
				sum/=10;
			}
			sum=tmp;
		}
	
	cout << ans << '\n';
	if(sum%3)cout << "NO";
	else cout << "YES";
}
