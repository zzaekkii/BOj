#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100][100];
int score[100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j;
	cin >> N >> M;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++) 
			cin >> arr[i][j];
		sort(arr[i],arr[i]+M);
	}
	
	for(i=0;i<M;i++){
		int temp = 0;
		for(j=0;j<N;j++)
			temp = max(temp, arr[j][M - i - 1]);
		for(j=0;j<N;j++)
			if (temp == arr[j][M - i - 1])
				score[j]++;
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, score[i]);
	
	for (int i = 0; i < N; i++)
		if (ans == score[i])
			cout << i + 1 << " ";
}
