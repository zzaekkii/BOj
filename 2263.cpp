#include <bits/stdc++.h>
using namespace std;

int in[100001], post[100001];
int pre[100001];
int N, ord;

void func(int is, int ie, int ps, int pe){
    if((ie-is)!=(pe-ps))return;
    for(int i=0;i<=ie-is;i++)
        if(in[is+i]==post[pe]){
            pre[ord++]=post[pe];
            func(is,is+i-1,ps,ps+i-1);
            func(is+i+1,ie,ps+i,pe-1);
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> in[i];
    for(int i=0;i<N;i++) cin >> post[i];
    func(0,N-1,0,N-1);
    for(int i=0;i<N;i++)
        cout << pre[i] << ' ';
}
