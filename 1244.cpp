#include <bits/stdc++.h>
using namespace std;

int SW, ST, G, N; // ����ġ ��, �л� ��, ����, ����ġ��ȣ 
bool sw[101]; // ����ġ ���� ���� �迭

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> SW;
    
    for(int i=1;i<=SW;i++) cin >> sw[i];
    	
    cin >> ST;
    
    while(ST--){
    	cin >> G >> N;
    	
    	switch(G){
    		case 1:
    			for(int i=N;i<=SW;i+=N) sw[i]=!sw[i];
    			break;
    		case 2:
    			sw[N]=!sw[N];
    			for(int i=1;;i++){
    				if((N-i)<1||(N+i)>SW)break;
    				if(sw[N-i]==sw[N+i])sw[N-i]=sw[N+i]=!sw[N+i];
    				else break;
				}
    			break;
		}
	}
    
    for(int i=1;i<=SW;i++){
    	if(i>20&&i%20==1) cout << '\n';
    	cout << sw[i] << ' ';
	}
}
