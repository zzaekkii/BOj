#include <bits/stdc++.h>
using namespace std;

int N;
int Arr[1001];
int lis[1001];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
        cin >> Arr[i];
    
    lis[0]=Arr[0];
    for(int i=1;i<N;i++){
        if(lis[ans]<Arr[i])
            lis[++ans]=Arr[i];
        else{
            int st=0,en=ans;
            while(st<en){
                int md=(st+en)/2;
                if(lis[md]<Arr[i])
                    st=md+1;
                else en=md;
            }
            lis[en]=Arr[i];
        }
    }
    
    cout << ans+1;
}
