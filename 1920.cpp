#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int A[100001];

int binarySearch(int t){
	int st=0, en=N-1;
	while(st<=en){
		int mid=(st+en)/2;
		if(A[mid]<t)st=mid+1;
		else if(A[mid]>t)en=mid-1;
		else return 1;
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++) cin >> A[i];
	sort(A, A+N);
	
	cin >> M;
	while(M--){
		cin >> T;
		cout << binarySearch(T) << '\n';
	}
}
