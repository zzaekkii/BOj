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
    
    int p, i=0; // ������(p: �� ������ �� �� ���� ��)
    // i: ���ڿ� �ε���.
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
		else{ // 10������ ��Ģ ����.(19,20,21)
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
	
	for(p=1;p<19;p+=2){ // 9�����ӱ��� ���.
		if(bonus[p]==2){ // ��Ʈ����ũ. 
			ans+=10;
			if(st[p+2])ans+=10+score[p+4];
			else ans+=score[p+2]+score[p+3];
		}
		else if(bonus[p]==1) // �����.
			ans+=10+score[p+2];
		else
			ans+=score[p]+score[p+1];
	}
	for(p=19;p<=21;p++) ans+=score[p]; // 10������ ���� �ջ�. 
	
	cout << ans;
}
