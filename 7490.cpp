#include <bits/stdc++.h>
using namespace std;

int T, N;

bool Zero(string s) {
	int sum=0, cur=0;
	char oper='+'; // 첫 숫자는 시작 값이니까. 
	int l=s.length();
	
	for (int i=0; i<l; i++){
		// 숫자 등장(이전 순서 공백인 경우 포함).
		if (s[i]>='0' && s[i]<='9') {
			cur = cur*10 + (s[i]-48);
		}
		// 기호 +, - 등장. 
		else if (s[i]=='+' || s[i]=='-') {
			if (oper=='+') sum+=cur;
			else sum-=cur;
			
			cur=0;
			oper=s[i]; 
		}
	}
	
	// 마지막 숫자 계산. 
	if (oper=='+') sum+=cur;
	else sum-=cur;
	
	if (!sum) return 1;
	return 0; 
}

void Dfs(int x, string s) {
	if (x==N) {
		if (Zero(s))
			cout << s << '\n';
		
		return;
	}
	
	Dfs(x+1, s+" "+to_string(x+1));
	Dfs(x+1, s+"+"+to_string(x+1));
	Dfs(x+1, s+"-"+to_string(x+1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while (T--) {
    	cin >> N;
    	Dfs(1, "1");
    	cout << '\n';
	}
}
