#include <bits/stdc++.h>
using namespace std;
int N;
string S;

map<string,bool> M;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    cin >> N;
    while(N--){
    	cin >> S;
    	if(!S.compare("ENTER"))
    		M.clear();
    	else if(M.find(S)==M.end()){
    		M.insert({S,1});
    		cnt++;
		}
	}
	cout << cnt;
}
