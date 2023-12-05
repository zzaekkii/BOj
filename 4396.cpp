#include <bits/stdc++.h>
using namespace std;
string bB[11],bA[11];
int N, arr[11][11];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};
bool f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++) cin >> bB[i];
    for(int i=0;i<N;i++) cin >> bA[i];
    
    for(int i=0;i<N;i++)
    	for(int j=0;j<N;j++){
    		if(bB[i][j]=='*'&&bA[i][j]=='x')f=1;
			            
			int cnt=0;
            for(int k=0;k<8;k++){
    			if(bB[i][j]=='*')break;
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0||nx>=N||ny<0||ny>=N)continue;
                if(bB[nx][ny]=='*')cnt++;
            }
            arr[i][j]=cnt;
    		if(bA[i][j]!='.')bA[i][j]=cnt+48;
		}
		
	if(f)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(bB[i][j]=='*')bA[i][j]='*';
	
	for(int i=0;i<N;i++)
		cout << bA[i] << '\n';			
}
