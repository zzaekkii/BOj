#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    int max_x = INT_MIN, min_x = INT_MAX, max_y=INT_MIN, min_y=INT_MAX;
    cin >> N;
    if (N == 1) {
        cout << 0;
        return 0;
    }
    while (N--) {
        int X, Y;
        cin >> X >> Y;
        if (max_x < X)max_x = X;
        if (min_x > X)min_x = X;
        if (max_y < Y)max_y = Y;
        if (min_y > Y)min_y = Y;
    }
    cout << (max_x - min_x) * (max_y - min_y);
}