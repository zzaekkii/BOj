#include <bits/stdc++.h>
using namespace std;

int A[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int d1, d2;
    cin >> A[0] >> A[1] >> A[2];
    sort(A,A+3);
    d1=A[1]-A[0];
    d2=A[2]-A[1];
    if(d1>d2)cout<<A[0]+d2;
    else if(d1==d2)cout<<A[2]+d1;
    else cout << A[1]+d1;
}
