#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N;
ll Arr[1'000'001];
ll lis[1'000'001];
ll rec[1'000'001]={0};
ll fin[1'000'001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
        cin >> Arr[i];
    
    lis[0]=Arr[0];
    int ans=0;    
    for(int i=1;i<N;i++){
        if(lis[ans]<Arr[i]){
            lis[++ans]=Arr[i];
            rec[i]=ans;
        }
        else{
            int l=0,r=ans;
            while(l<r){
                int m=(l+r)/2;
                if(lis[m]<Arr[i])
                    l=m+1;
                else
                    r=m;
            }
            lis[r]=Arr[i];
            rec[i]=r;
        }
    }
    
    int mx=ans;
    for(int i=N-1;i>=0;i--)
        if(mx==rec[i])
            fin[mx--]=Arr[i];
    
    cout << ++ans << '\n';
    for(int i=0;i<ans;i++)
        cout << fin[i] << ' ';
}
