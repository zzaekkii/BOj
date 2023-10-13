#include <bits/stdc++.h>
using namespace std;

int cnt;
int A, B;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    
    while(B){
    	cnt++;
    	if(B<A){
			cout << -1;
			return 0;
		}
    	if(B==A)break;
    	else if(B%10==1)B/=10;
    	else if(!(B%2))B/=2;
    	else{
			cout << -1;
			return 0;
		}
	}
	cout << cnt;
}
