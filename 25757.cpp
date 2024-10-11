#include <bits/stdc++.h>
using namespace std;

int N;
char G;
string S;
unordered_map<string,bool> M;
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> G;
    
    int need=0;
    if(G=='Y')need=1;
    else if(G=='F')need=2;
    else if(G=='O')need=3;
    
    int cnt=0;
    while(N--){
    	cin >> S;
    	if(!M[S]){
    		M[S]=1;
    		cnt++;
		}
	}
	
	cout << cnt/need;
}
