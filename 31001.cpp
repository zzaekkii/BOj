#include <bits/stdc++.h>
using namespace std;

int N,Q, G,P, O, B,D;
long long M; // 주가가 최대치일 때 여러 개 팔면? int 범위 초과.
double E;
string H,A;

map<string,long long> C; // 회사 별 주가.
vector<string> group[101]; // 그룹에 속한 회사.
map<string,int> W; // 내 주식 계좌.

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> Q; // 기업 수, 보유 현금, action 수. 
	
	for(int i=0;i<N;i++){
		cin >> G >> H >> P; // 그룹 번호, 회사 이름, 주가. 
		group[G].push_back(H); // 그룹 번호 G에 속한 H.
		C[H]=P; // H 회사의 주가는 P. 
		W[H]=0; // 거래 전 기본 값은 0. 
	}
	
	while(Q--){
		cin >> O;
		
		int l=0;
		switch(O){
			case 1: // (내가) A회사 주식 B주 구매.
				cin >> A >> B; 
				if(M>=C[A]*B){ // 살 수 있을 때만 구매. 
					M-=C[A]*B;
					W[A]+=B;
				}
				break;
			case 2: // (내가) A회사 주식 B주 판매.
				cin >> A >> B;
				if(B>=W[A]){ // B보다 적게 가졌으면 있는 거 다 팔기(0포함). 
					M+=C[A]*W[A];
					W[A]=0;
				}
				else if(W[A]>B){ // B주만큼 팔기. 
					M+=C[A]*B;
					W[A]-=B;
				}
				break;
			case 3: // A회사 주식 B원 상승/하락.
				cin >> A >> B;
				C[A]+=B;
				if(C[A]<0)C[A]=0; // 0이상 보장
				break;
			case 4: // 그룹 번호 D에 속한 회사들 주가 B원 상승/하락. 
				cin >> D >> B;
				l=group[D].size();
				
				for(int i=0;i<l;i++){
					C[group[D][i]]+=B;
					if(C[group[D][i]]<0)C[group[D][i]]=0;
				}	
				break;
			case 5: // 그룹 번호 D에 속한 회사들 주가 E% 상승/하락.
				cin >> D >> E;
				
				E/=100;
				l=group[D].size();
				
				for(int i=0;i<l;i++){
					C[group[D][i]]+=C[group[D][i]]*E;
					C[group[D][i]]-=C[group[D][i]]%10; // 일의 자리 버림.
                    if(C[group[D][i]]<0)C[group[D][i]]=0;
				}
				break;
			case 6: // (내가) 보유한 현금 출력. 
				cout << M << '\n';
				break;
			case 7: // (내) 총 자산(현금+주식) 출력. 
				long long asset=M;
				for(auto it=W.begin();it!=W.end();it++)
					asset+=(long long)C[it->first]*(it->second);
				cout << asset << '\n';
				break;
		}
	}
}
