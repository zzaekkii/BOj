#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i, j;
	cin >> N;
	
	while(N--){
		int O, X;
		cin >> O;
		switch(O){
			case 1:
				cin >> X;
				S.push(X);
				break;
			case 2:
				if(S.empty())cout << -1 << '\n';
				else{
					cout << S.top() << '\n';
					S.pop();
				}
				break;
			case 3:
				cout << S.size() << '\n';
				break;
			case 4:
				if(!S.empty())cout << 0 << '\n';
				else cout << 1 << '\n';
				break;
			case 5:
				if(S.empty())cout << -1 << '\n';
				else cout << S.top() << '\n';
				break;
		}
	}
}
