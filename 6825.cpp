#include <bits/stdc++.h>
using namespace std;
#define ll long long
double W, H;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> W >> H;
    if (W / pow(H, 2) > 25) cout << "Overweight";
    else if (W / pow(H, 2) > 18.5) cout << "Normal weight";
    else cout << "Underweight";
}
