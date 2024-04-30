#include <bits/stdc++.h>
using namespace std;

int K;
int S[14];
vector<int> lot;

void dfs(int idx){
    if(lot.size()==6){
        for(int i=0;i<6;i++)
            cout << lot[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=idx;i<K;i++){
        lot.push_back(S[i]);
        dfs(i+1);
        lot.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> K;
        if(!K)break;
        for(int i=0;i<K;i++)cin >> S[i];
        dfs(0);
        cout << '\n';
    }
}
