#include <bits/stdc++.h>
using namespace std;
int L,P,V,i;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
	while(1){
		cin >> L >> P >> V;
		if(!L&&!P&&!V)break;
		cout << "Case " << ++i << ": " << V/P*L+min(V%P,L) << '\n';
    }
}
