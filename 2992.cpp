// 2992번 크면서 작은 수 - 실버3 / #백트래킹 
#include <bits/stdc++.h>
using namespace std;

string X, A;
int num[7];
bool vis[7];
int len;

string ans;

int isBiggerThanX(string y, string z){
	if(y>z)return 1;
	if(y==z)return -1;
	return 0;
}

void makeNum(int cnt){
	if(cnt==len){
		int tmp=isBiggerThanX(A, X);
		if(tmp==1){ // 크다. 
			if(ans.empty()||A<ans)
				ans=A;
		}
		return;
	}
	
	for(int i=0;i<len;i++){
		if(!vis[i]){
			vis[i]=1;
			A[cnt]=num[i]+48;
			makeNum(cnt+1);
			vis[i]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> X;
	
	len=X.length();
	A=string(len, '0');
	
	for(int i=0;X[i];i++)
		num[i]=X[i]-48;
	
	sort(num,num+len);
	
	makeNum(0);
	
	if(!ans.empty())cout << ans;
	else cout << 0;
}
