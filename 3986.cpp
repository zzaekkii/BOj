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
    		if(stk.size()&&stk.top()==a)stk.pop(); // ���� �� ������ pop.
    		else stk.push(a); // �ٸ��� ����.
		}
		if(!stk.size())cnt++; // ���� ������ ��� ī��Ʈ ����. 
	}
	cout << cnt;
}
