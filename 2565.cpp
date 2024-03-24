#include <bits/stdc++.h>
using namespace std;

struct LINE{
	int L,R;
};

bool cmp(LINE a, LINE b){ // c에서의 compare와는 달리 bool값 반환. 
	return a.L < b.L; // 오름차순. 
}

int N;
LINE Arr[101];
int lis[101];
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
	
    for(int i=0;i<N;i++)
    	cin >> Arr[i].L >> Arr[i].R;
    
    sort(Arr,Arr+N,cmp);
    
    lis[0]=Arr[0].R;
    int idx=1,cnt=0;
    
    for(;idx<N;idx++){
    	if(Arr[idx].R>lis[cnt])
    		lis[++cnt]=Arr[idx].R;
    	else{
    		int st=0,en=cnt;
    		while(st<en){
    			int md=(st+en)/2;
    			if(lis[md]<Arr[idx].R)
    				st=md+1;
    			else
    				en=md;
			}
			lis[en]=Arr[idx].R;
		}
	}
	cout << N-(cnt+1);
}
