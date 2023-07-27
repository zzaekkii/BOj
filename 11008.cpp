#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){ 
        string s,p;
        cin >> s >> p;
        int cnt = 0;
 
        for(int i = 0;i<s.size();i++){
            string temp = "";
            if(i+p.size()<=s.size()){
                for(int j = i;j<i+p.size();j++)
                    temp = temp + s[j];
                if(temp == p){ 
                    cnt++;
                    i = i + p.size()-1;
                }
                else cnt++;
            }
            else cnt++; 
        }
        cout << cnt << '\n';
    }
}
