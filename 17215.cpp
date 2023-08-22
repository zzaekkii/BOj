#include <bits/stdc++.h>
using namespace std;
string S;
int score[23];
int bonus[23];
bool st[23];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> S;
    
    int p, i=0; // 프레임(p: 각 프레임 걍 두 개로 함)
    // i: 문자열 인덱스.
    for(p=1;p<=19;p++,i++){
    	if(p!=19){
    		switch(S[i]){
    			case 'S':
    				bonus[p]=2;
    				score[p]=10;
    				st[p]=1;
    				p++;
    				break;
    			case '-':
    				break;
    			default:
    				if(S[i]=='P'){
    					bonus[p-1]=1;
    					score[p]=10-score[p-1];
					}
    				else if(S[i]>48&&S[i]<58)score[p]=S[i]-48;
    				break;
			}
		}
		else{ // 10프레임 규칙 적용.(19,20,21)
			while(S[i]){
				if(S[i]=='S')
					score[p]=10;
				else if(S[i]=='-');
				else if(S[i]=='P') score[p]=10-score[p-1];
				else score[p]=S[i]-48;
				p++,i++;
			} 
		}
	}
	
	for(p=1;p<19;p+=2){ // 9프레임까지 계산.
		if(bonus[p]==2){ // 스트라이크. 
			ans+=10;
			if(st[p+2])ans+=10+score[p+4];
			else ans+=score[p+2]+score[p+3];
		}
		else if(bonus[p]==1) // 스페어.
			ans+=10+score[p+2];
		else
			ans+=score[p]+score[p+1];
	}
	for(p=19;p<=21;p++) ans+=score[p]; // 10프레임 점수 합산. 
	
	cout << ans;
}
