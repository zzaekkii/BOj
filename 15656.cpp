#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];

void func(int t) {
    if (t == M) {
        for (int i = 0; i < M; i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0;i<N;i++){
            arr[t] = num[i];
            func(t+1);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> num[i];
    sort(num,num+N);
    func(0);
}
