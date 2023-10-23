#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
int arr[11]={1,9,9, 90, 90}, sum[11]={1,9,18};
int l, ans, tmp=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    l=S.length();

    for(int i=5;i<11;i++){
        if(i%2){
            arr[i]=9*arr[i-2];
        }
        else arr[i]=arr[i-1];
    }
    for(int i=2;i<11;i++)sum[i]=arr[i];
    for(int i=2;i<11;i++)sum[i]+=sum[i-1];
    ans=sum[l-1];

    if(l==2){
        if(S[0]<=S[1])ans+=S[0]-48;
        else ans+=S[0]-49;
    }
    if(l>2){
        ans+=((S[0]-48)-1)*pow(10,(l-1)/2);
        for (int i = 1; i <= l / 2; i++) {
            if (S[i] <= S[l - 1 - i])tmp *= (S[i] - 48);
        }
        ans+=tmp;
        ans+=S[0]==S[l-1];
    }
    cout << ans;
}
