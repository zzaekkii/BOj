#include <bits/stdc++.h>
using namespace std;

int N, D, C;
int arr[200'001];
int miin[200'001];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--){
        cin >> D >> C;
        int mmin=0x7fffffff;
        for(int i=D;i>0;i--)
            if(mmin>arr[i])mmin=arr[i];
        memset(miin,mmin,D);
            
        for(int i=D;i>0;i--){
            if(miin[i]>C)break;
            if(arr[i]<C){
                int tmp=arr[i];
                arr[i]=C;
                C=tmp;
            }
        }
    }
    for(int i=1;i<200'001;i++) ans+=arr[i];
    cout << ans;
}
