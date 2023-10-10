#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> S;
        char c=0;
        for(int i=0;i<S.length();i++)
            if(c!=S[i]){
                cout << S[i];
                c=S[i];
            }
        cout << '\n';
    }
}
