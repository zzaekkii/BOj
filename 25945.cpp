#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int N,sum,avg,u_top,bot;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;	
	for(int i=0;i<N;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    avg=sum/N;
    for(int i=0;i<N;i++)
        if(arr[i]<avg) bot+=avg-arr[i];
        else if(arr[i]>avg+1) u_top+=arr[i]-(avg+1);
    if(u_top<=bot) cout << bot;
    else cout << u_top;
}
