#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];
bool isused[10000];

void func(int t) {
    if (t == M) {
        for (int i = 0; i < M; i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0;i<N;i++)
        if (!isused[num[i]]) {
            arr[t] = num[i];
            isused[num[i]] = 1;
            func(t + 1);
            isused[num[i]] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> num[i];
    sort(num,num+N);
    func(0);
}
