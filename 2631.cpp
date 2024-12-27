// 2631번 줄세우기 - 골드4 / #LIS 
#include <bits/stdc++.h>
using namespace std;

int N;
int seq[201];
int lis[201];

int cnt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> seq[i];
	
	lis[0]=seq[0];
	
	for(int i=1;i<N;i++)
		if(lis[cnt]<seq[i])
			lis[++cnt]=seq[i];
		else{
			int st=0,en=cnt;
			while(st<en){
				int md=(st+en)/2;
				
				if(lis[md]<seq[i])
					st=md+1;
				else en=md;
			}
			lis[en]=seq[i];
		}
	
	cout << N-(cnt+1);
}
