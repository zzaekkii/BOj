#include <bits/stdc++.h>
using namespace std;

int coin[5]={ 0, 1, 2, 5, 7 };
int N;
int dp[100001];

int main() {
    cin >> N;
    for (int i = 1;i<=N; i++)
        dp[i] = 100000;
    dp[0] = 0;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= 4; j++)
            if (i >= coin[j])
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);

    cout << dp[N];
}
