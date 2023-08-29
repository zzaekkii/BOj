#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int A[500001];
int B[500001];
vector<int> V;

int binarySearch(int t){
	int st=0, en=M-1;
	while(st<=en){
		int mid=(st+en)/2;
		if(B[mid]<t)st=mid+1;
		else if(B[mid]>t)en=mid-1;
		else return 1;
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++) cin >> A[i];
	sort(A, A+N);
	for(int i=0;i<M;i++) cin >> B[i];
	sort(B, B+M);
	
	int cnt=0;
	for(int i=0;i<N;i++)
		if(!binarySearch(A[i])){
			cnt++;
			V.push_back(A[i]);
		}
	cout << cnt << '\n';
	for(auto a: V) cout << a << ' ';
}
