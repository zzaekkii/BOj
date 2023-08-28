#include <bits/stdc++.h>
using namespace std;
int T, N;
pair<int,int> A[100000]; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> N;
    	for(int i=0;i<N;i++)
    		cin >> A[i].first >> A[i].second;
    		
    	sort(A, A+N);
    	
    	int cut=A[0].second, cnt=1;
    	for(int i=1;i<N;i++){
    		if(A[i].second<cut){
    			cnt++;
    			cut=A[i].second;
			}
		}
		cout << cnt << '\n';
	}
}
