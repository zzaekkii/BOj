#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[1000001];
int lis[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
        cin >> Arr[i];
    
    lis[0]=Arr[0];
    int idx=1,ans=0;
    
    for(;idx<N;idx++){
        if(lis[ans]<Arr[idx])
            lis[++ans]=Arr[idx];
        else{
            int l=0,r=ans;
            while(l<r){
                int m=(l+r)/2;
                if(lis[m]<Arr[idx])
                    l=m+1;
                else
                    r=m;
            }
            lis[r]=Arr[idx];
        }
    }
    
    cout << ans+1;
}
