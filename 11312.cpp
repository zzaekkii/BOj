#include <bits/stdc++.h>
#define ll long long
using namespace std;
double T,A,B;

int main(){
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << (ll)ceil(A/B * A/B) << '\n';
    }
}
