#include <bits/stdc++.h>
using namespace std;

int N;
string S[51];

int cmp(string a, string b){
	int len_a=a.size(),len_b=b.size();
	if(len_a!=len_b) return len_a<len_b;
	
	int sum_a=0,sum_b=0;
	for(int i=0;i<len_a;i++){
		if(a[i]>48&&a[i]<58)sum_a+=a[i]-48;
		if(b[i]>48&&b[i]<58)sum_b+=b[i]-48;
	}
	
	if(sum_a!=sum_b) return sum_a<sum_b;
	
	return a<b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> S[i];
    sort(S,S+N,cmp);
    for(int i=0;i<N;i++) cout << S[i] << '\n';
}
