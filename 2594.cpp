#include <bits/stdc++.h>
using namespace std;
 
int N;
vector<pair<int,int>> A; // 시작시간, 종료시간

int time(int t){
    return (t / 100 * 60) + (t % 100);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, answer = 0, last = 600;
    cin >> n;
    for(int i = 0; i < N; i++){
    	cin >> a >> b;
    	A.push_back(make_pair(time(a)-10,time(b)+10));
    }
    A.push_back(make_pair(1320,0));
    sort(A.begin(),A.end());
    for(int i = 0; i <=N; i++){
        answer = max(answer, A[i].first - last);
        last = max(last, A[i].second);
    }
    cout << answer;
}

/*
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> A; // 시작시간, 종료시간

int time(int t){
    return (t / 100 * 60) + (t % 100);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int max=0, term, a, b;
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> a >> b;
    	A.push_back(make_pair(time(a)-10,time(b)+10));
    }
    A.push_back(make_pair(1320,0));
    sort(A.begin(),A.end());
    
    term=A[0].first-600;
    if(term>max)max=term;
    
    for(int i=1;i<=N;i++){
    	term=A[i].first-A[i-1].second;
    	if(term>max)max=term;
    }
	
	cout << max;
}
*/
