// 7353번 합이 0인 네 정수 - #이분탐색 
#include <bits/stdc++.h>
using namespace std;

int N;
int A[4][4001];

int ab[16'000'001];
int cd[16'000'001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	for(int j=0;j<4;j++)
    		cin >> A[j][i];
    
    int idx=0;
    for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++){
    		ab[idx]=A[0][i]+A[1][j];
    		cd[idx++]=A[2][i]+A[3][j];
		}
	
	sort(ab,ab+idx);
	sort(cd,cd+idx);
	
	long long cnt=0;
	for(int i=0;i<idx;i++){
		auto range = equal_range(cd, cd+idx,-ab[i]);
		cnt+=range.second-range.first;
	}
	
	cout << cnt;
}
