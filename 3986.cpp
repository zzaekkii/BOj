#include <bits/stdc++.h>
using namespace std;
int N, cnt=0;
string S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    while(N--){
    	stack<char> stk;
    	cin >> S;
    	
    	for(char a: S){
    		if(stk.size()&&stk.top()==a)stk.pop(); // 같은 게 붙으면 pop.
    		else stk.push(a); // 다르면 보관.
		}
		if(!stk.size())cnt++; // 최종 스택이 비면 카운트 증가. 
	}
	cout << cnt;
}
