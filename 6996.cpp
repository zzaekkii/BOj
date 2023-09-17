#include <bits/stdc++.h>
using namespace std;
int N;
string A, B;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    while(N--){
    	cin >> A >> B;
    	cout << A << " & " << B << " are ";
    	
    	sort(A.begin(), A.end());
    	sort(B.begin(), B.end());
    	
    	if(A.compare(B)!=0) cout << "NOT ";
    	cout << "anagrams.\n"; 
	}    
}