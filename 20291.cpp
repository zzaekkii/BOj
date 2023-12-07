#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
vector<pair<string,int>> ans;
vector<string> V;
string S,ex;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
	for(int i=0;i<N;i++){
		cin >> S;
		S.erase(0,S.find('.')+1);
		V.push_back(S);		
	}
	sort(V.begin(),V.end()); 

	int cnt=0;
	ex=V[0];
	for(int i=0;i<V.size();i++){
		if(ex==V[i])cnt++;
		else if(ex!=V[i]){
			ans.push_back(pair<string,int>(ex,cnt));
			ex=V[i];
			cnt=1;
		}
	}
	ans.push_back(pair<string,int>(ex,cnt));

	for(int i=0;i<ans.size();i++)
		cout << ans[i].X << ' ' << ans[i].Y << '\n';		
}
