#include <bits/stdc++.h>
using namespace std;

struct Flower{
	int b,f;
	// int sm,sd,em,ed;
};

// 3월 1일 => 31+28+1 => 60
// 12월 1일 => 365-31+1 => 335
// 개화 <= 60, 낙화 >=335 
int bloom[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int N,Sm,Em;
Flower F[100001];

bool cmp(Flower x,Flower y){
	if(x.b==y.b)return x.f<y.f;
	else return x.b<y.b;
}

//bool cmp(Flower a,Flower b){
//	if(a.sm==b.sm)
//		if(a.sd==b.sd)
//			if(a.em==b.em)return a.ed<b.ed;
//			else return a.em<b.em;
//		else return a.sd<b.sd;
//	else return a.sm<b.sm;
//}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> Sm >> F[i].b >> Em >> F[i].f;
    	for(int j=1;j<Sm;j++)F[i].b+=bloom[j];
    	for(int j=1;j<Em;j++)F[i].f+=bloom[j];
    }
    
    sort(F,F+N,cmp);
	
	int now=60,mx=0,idx=0,ans=0;
	
	for(int i=0;i<N;i++){
		if(now>=335)break; // 12월1일~
		 
		if(mx<F[i].f&&F[i].b<=now){ // 현재 포함, 최대 길이 탐색. 
			idx=i;
			mx=F[i].f; // 가장 늦게 지는 꽃. 
		}
		
		if(mx==0){
			ans=0;
			break;
		}else if(F[i].b>now){
			now=F[idx].f; // 지금껏 찾은 최장 꽃 낙화일(이제 이걸 포함해야 함).
			ans++; // 꽃 증가.
			i--; // 꽃 변경 후, 재검토. 
			mx=0; // 새로운 꽃 찾기. 
		}else if(i==N-1){
			now=F[idx].f;
			ans++;
		}
	}
	
	if(now<335)ans=0;
	cout << ans;
}
