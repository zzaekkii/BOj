#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int t) {
    if (t == M) {
        for (int i = 0; i < M; i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++){
            arr[t] = i;
            func(t + 1);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    func(0);
}
