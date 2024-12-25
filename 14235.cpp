#include <bits/stdc++.h>
using namespace std;

int N, O, T;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    while(N--){
        cin >> O;
        
        if(O){
            while(O--){
                cin >> T;
                pq.push(T);
            }
        }
        else{
            if(pq.empty())cout << -1 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
