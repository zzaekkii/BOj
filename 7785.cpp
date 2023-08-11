#include <bits/stdc++.h>
using namespace std;

int N;
set<string> M;
string Name, Ent; 

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	
	while(N--){
		cin >> Name >> Ent;
		if(!Ent.compare("leave"))M.erase(Name);
		else M.insert(Name);
	}
	
	for (auto a = M.rbegin(); a != M.rend(); a++)
        cout << *a << '\n';
}
