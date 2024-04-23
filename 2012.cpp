#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[500001];
long long ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> Arr[i];
	
	sort(Arr,Arr+N);
    
    int tmp;
	for(int i=0;i<N;i++){
        tmp=abs(i+1-Arr[i]);
        ans+=tmp;
	}
	cout << ans;
}
