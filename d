#include <bits/stdc++.h>
using namespace std;
int N,M,J,T;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> J;
    
    int cnt=0;
    int start=1, end = M;

    while(J--) {
        int x;
        cin >> x;

        bool f=1;
        while(f){
            if(start<=x && x<=end)f=0;
            else if(start>x){
                start--; end--; cnt++;
            } else {
                start++; end++; cnt++;
            }
        }
    }
    cout << cnt;
}
