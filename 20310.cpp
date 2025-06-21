#include <bits/stdc++.h>
using namespace std;

string S;
int cnt[2];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    
    for(int i=0;S[i];i++)
        if(S[i]=='0')cnt[0]++;
        else cnt[1]++;
    
    cnt[0]/=2;
    cnt[1]/=2;
    
    string tmp;
    for(int i=0;S[i];i++){
        if(S[i]=='1'&&cnt[1]){
            cnt[1]--;
            continue;
        }
        tmp+=S[i];
    }
    
    string ans;
    for(int i=tmp.size()-1;i>=0;i--){
        if(tmp[i]=='0'&&cnt[0]){
            cnt[0]--;
            continue;
        }
        ans+=tmp[i];
    }
    
    reverse(ans.begin(),ans.end());
    
    cout << ans;
}
