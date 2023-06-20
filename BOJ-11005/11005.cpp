#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int N, B;
	cin >> N >> B;
	string ans;
	while(N){
		int tmp=N%B;
		if(tmp>9){
			ans+=tmp+55;
		}
		else ans+=tmp+48;
		N/=B;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
