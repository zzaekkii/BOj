#include <bits/stdc++.h>
using namespace std;

int N, A, B;
vector<pair<int,int>> V;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int sum=0;
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> A >> B;
    	V.push_back(make_pair(A,B));
	}
	sort(V.begin(),V.end());
	
	A=V[0].first;
	B=V[0].second;
	
	for(int i=1;i<N;i++)
		if(B>V[i].first){ // ���� ���� ���� ���������� �� 
			if(V[i].second>B)B=V[i].second; // ������ ���� ������ �� 
		}
		else{
			sum+=B-A;
			A=V[i].first;
			B=V[i].second;
		}
		
	sum+=B-A;
	cout << sum;
}
