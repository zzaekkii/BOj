#include <bits/stdc++.h>
using namespace std;

int N;
int A[100001];
int ans=1,inc=1,decr=1;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++)
        cin >> A[i];
    for(int i=1;i<N;i++){
        if(A[i]<=A[i+1])inc++;
        else inc=1;
        
        if(A[i]>=A[i+1])decr++;
        else decr=1;
        
        ans=max(ans,max(inc,decr));
    }
    cout << ans;
}
