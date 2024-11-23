// 1019번 책 페이지 - #수학 
#include <bits/stdc++.h> 
using namespace std;

int N;
int ans[10]; 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    // 왼쪽, 현재, 오른쪽, 자릿수. 
    int lt=1,cur=0,rt=0,k=1;
    while(lt){
    	lt=N/(k*10),cur=(N/k)%10,rt=N%k;
    	
    	for(int i=0;i<10;i++){
    		// 0은 특이케이스임(앞 자리엔 0이 없음) 
    		if(!i&&!lt)continue;
			
			if(cur>i)
	    		ans[i]+=(lt+1)*k;
	    	else if(cur==i)
	    		ans[i]+=(lt*k)+rt+1;
	    	else
	    		ans[i]+=lt*k;
		 	
	    	if(!i)
				ans[i]-=k;
	    }
		k*=10;
	}
	
	for(int i=0;i<10;i++)
		cout << ans[i] << ' ';
}
