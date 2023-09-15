#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10];
bool isused[10];

void func(int t) {
    if (t == N) {
        for (int i = 0; i < N; i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++)
        if (!isused[i]) {
            arr[t] = i;
            isused[i] = 1;
            func(t + 1);
            isused[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    func(0);
}
