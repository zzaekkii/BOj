#include <bits/stdc++.h>
using namespace std;

int N, M, T, P, tmp, cnt; // 총원, 파티 수, 현자 수, 사람 수 
bool Truth[51];
vector<int> Person[51];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    
    for(int i=0;i<T;i++){
    	cin >> tmp;
    	Truth[tmp]=1;
	}
	
	int V;
	for(int i=0;i<M;i++){
		bool flag=0;
		cin >> P;
		for(int j=0;j<P;j++){
			cin >> V;
			Person[i].push_back(V);
			if(Truth[V])flag=1;
		}
		if(flag)for(int j=0;j<P;j++)Truth[Person[i][j]]=1;
	}
	
	while(N--)		
		for(int i=0;i<M;i++){
			bool flag=0;
			int l=Person[i].size();
			for(int j=0;j<l;j++)
				if(Truth[Person[i][j]])flag=1;
			if(flag)for(int j=0;j<l;j++)Truth[Person[i][j]]=1;
		}
		
	for(int i=0;i<M;i++)
		if(!Truth[Person[i][0]])cnt++;
    
    cout << cnt;
}
