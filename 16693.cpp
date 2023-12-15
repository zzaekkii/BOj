#include <bits/stdc++.h>
using namespace std;
double A,P1,R,P2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A1 >> P1 >> R >> P2;
    double w=R*R*3.14159/P2;
    double s=A/P1;
    if(w>s) cout << "Whole pizza";
    else cout << "Slice of pizza";
}
