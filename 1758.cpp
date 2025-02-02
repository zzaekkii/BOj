// 1758번 알바생 강호 - 실버4 / 그리디
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100001];
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> arr[i];
	
	sort(arr,arr+N,greater<int>());
	
	for(int i=0;i<N;i++)
		ans+=max(arr[i]-i,0);
	
	cout << ans;
}
