#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int n,int t){
    if(t==M){
        for(int i=0;i<M;i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=n;i<=N;i++)
        if(!isused[i]){
            arr[t]=i;
            isused[i]=1;
            func(i+1,t+1);
            isused[i]=0;
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    func(1,0);
}
