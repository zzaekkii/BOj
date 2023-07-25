#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1000001];
stack<int> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int i, tmp;
    cin >> N;
    
    for(i=0;i<N;i++)
    	cin >> arr[i];

	for(i=N-1;i>=0;i--){
		while(!S.empty()&&S.top()<=arr[i]) S.pop();
		tmp=arr[i];
		if(S.empty()) arr[i]=-1;
		else arr[i]=S.top();
		S.push(tmp);
	}
	for(i=0;i<N;i++) cout << arr[i] << ' ';
}
