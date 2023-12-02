#include <bits/stdc++.h>
using namespace std;
int N,T;
int arr[1000][1000];
int ax,ay;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    
    int x=0,y=1;
    arr[0][0]=N*N;
    arr[1][0]=N*N-1;
    if(T==N*N)ay=1,ax=1;
    if(T==N*N-1)ay=2,ax=1;
    
    for(int v=N*N-2;v>0;v--){
    	if(arr[y][x])
	    	for(int i=0;i<4;i++){
	    		int nx=x+dx[i];
	    		int ny=y+dy[i];
				if(arr[ny][nx]==v+2){
					if(i%2){
						if(i==1)y+=1;
						else y-=1;
						
						if(y>=N){
							y-=1;
							x+=1;
						}
						else if(y<0){
							y+=1;
							x-=1;
						}
						else if(arr[y][x]){
							if(i==1){
								y-=1;
								x+=1;
							}
							else{
								y+=1;
								x-=1;
							}
						}
					}
					else{
						if(!i)x+=1;
						else x-=1;
						
						if(x>=N){ // 오른쪽 바깥
							x-=1;
							y-=1;
						}
						else if(arr[y][x]){ // 이미 채운 곳 
							if(!i){
								x-=1;
								y-=1;
							}
							else{
								x+=1;
								y+=1;
							}
						}						
					}	
					break;
				}
			}
		arr[y][x]=v;
		if(v==T)ax=x+1,ay=y+1;
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
 	}
 	cout << ay << ' ' << ax;
}
