#include <bits/stdc++.h>
using namespace std;

string A,B;
string ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    
    if(A.length()<B.length())swap(A,B);
    int len_A=A.length(),len_B=B.length();
    
    int sum=0,carry=0;
    for(int i=0;i<len_A;i++){
        sum=carry;
        sum+=A[len_A-1-i]-48;
        
        if(i<len_B)sum+=B[len_B-1-i]-48;
        
        carry=sum/2;
        ans+=sum%2+48;
    }
    
    if(carry)ans+=49;
    
    reverse(ans.begin(),ans.end());
    
    int len=ans.length();
    int idx=0;
    for(idx;idx<len-1;idx++)
        if(ans[idx]==49)break;
    
    for(;idx<len;idx++)
        cout << ans[idx];
}
