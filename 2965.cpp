#include <bits/stdc++.h>
using namespace std;
int K[3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> K[0] >> K[1] >> K[2];
	sort(K,K+3);
 	cout << max(K[2]-K[1],K[1]-K[0])-1;
}
