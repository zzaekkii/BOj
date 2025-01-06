// 5104번 NoMoPhobia - 실버4 / #해시맵 
#include <bits/stdc++.h>
using namespace std;

string cd[]={"TT","TX","PR","RT","AP","PX"};
int point[]={75,50,80,30,25,60};

int N, W; // N주차, W번 적발.
string stu_name, code;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(1){
		cin >> N >> W;
		
		if(!N&&!W)break;
		
		unordered_map<string,int> M;
		vector<string> seq;
		for(int i=0;i<W;i++){
			cin >> stu_name >> code;
			
			int idx=0;
			for(int j=0;j<6;j++)
				if(cd[j]==code)idx=j;
				
			if(M.find(stu_name)==M.end())
                seq.emplace_back(stu_name);
			
			M[stu_name]+=point[idx];
		}
		
		// 순서가 좀 걸리긴 하는군. 
		vector<string> V;
		cout << "Week " << N << ' ';
		for(const string name: seq)
			if(M[name]>=100)V.emplace_back(name);
		
		int l=V.size();
		if(l>0){
			for(int i=0;i<l-1;i++)
				cout << V[i] << ',';
			cout << V[l-1] << '\n';
		}
		else cout << "No phones confiscated\n";
	}
}
