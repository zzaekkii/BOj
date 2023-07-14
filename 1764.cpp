#include <bits/stdc++.h>
using namespace std;
int N, M;
string S; 

map<string,bool> P;
vector<string> V;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, cnt=0;
    cin >> N >> M;
    
    for(i=0;i<N;i++){
    	cin >> S;
    	P.insert({S,1});
	}
	for(i=0;i<M;i++){
		cin >> S;
		if(P[S]){
			V.push_back(S);
			cnt++;
		}
	}
	sort(V.begin(),V.end());
	cout << cnt << "\n";
	for(auto a: V) cout << a << "\n";
}
