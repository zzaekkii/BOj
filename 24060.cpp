#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[500001];
int tmp[500001];

int cnt;

void merge(int p, int q, int r){
	int i = p, j = q + 1, t = 0;
	
	while(i <= q && j <= r){
		if(A[i] <= A[j])tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
	}
	
	// 왼쪽 배열부 남음. 
	while(i <= q)
		tmp[t++] = A[i++];
	
	// 오른쪽 배열부 남음.
	while(j <= r)
		tmp[t++] = A[j++];
	
	i = p;
	t = 0;
	
	while(i <= r){
		A[i++] = tmp[t++];
		cnt++;
		
		if(cnt == K){
			cout << A[i-1];
			exit(0);
		}
	}
}

void merge_sort(int p, int r){
	if(p < r){
		int q = (p + r) / 2;
		
		merge_sort(p, q); // 전반부 정렬. 
		merge_sort(q + 1, r); // 후반부 정렬. 
		merge(p, q, r);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	for(int i = 0; i < N; i++)
		cin >> A[i];
	
	merge_sort(0, N-1);
	
	cout << -1;
}
