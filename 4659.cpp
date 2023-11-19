#include <bits/stdc++.h>
using namespace std;
string S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(1){
    	cin >> S;
    	if(!S.compare("end"))break;
    	cout << "<" << S << "> is ";
    	
    	int l=S.length();
    	bool f=0,v=0;
    	int con=0,vow=0;
    	
		for(int i=con=vow=0;i<l;i++){
			if(i>0&&S[i]==S[i-1]){
				if(S[i]=='e'||S[i]=='o');
				else f=1;
			}
    		switch(S[i]){
    			case 'a':
    			case 'e':
    			case 'i':
    			case 'o':
    			case 'u':
    				v=1;
    				con=0;
    				vow++;
    				if(vow>2)f=1;
    				break;
    			default:
    				vow=0;
    				con++;
    				if(con>2)f=1;
    				break;
			}
		}
		if(!v||f) cout << "not ";	
    	cout << "acceptable.\n";
	}
}
