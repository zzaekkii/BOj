#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,L,R;
int A[51][51];

int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
queue<pair<int,int>> Q;
int days;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L >> R;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
	
	while(1){
		bool br=1;
		bool vis[51][51]={0};
				
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(!vis[i][j]){
					int sum=0;
					vector<pair<int,int>> V;
					vis[i][j]=1;
					Q.push({i,j});
					
					while(!Q.empty()){
						auto cur=Q.front(); Q.pop();
						V.push_back({cur.X,cur.Y});
						sum+=A[cur.X][cur.Y];
						
						for(int dir=0;dir<4;dir++){
							int nx=cur.X+dx[dir];
							int ny=cur.Y+dy[dir];
							
							if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]){
								int tmp=abs(A[cur.X][cur.Y]-A[nx][ny]);
								if(tmp>=L&&tmp<=R){
									vis[nx][ny]=1;
									Q.push({nx,ny});
									br=0;
								}
							}
						}
					}
					
					int l=V.size();
					sum/=l;
					for(int k=0;k<l;k++)
						A[V[k].X][V[k].Y]=sum;
				}
			}
		
		if(br)break;
		days++;
	}	
	cout << days;
}
