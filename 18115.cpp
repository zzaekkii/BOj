#include <bits/stdc++.h>
using namespace std;
int N;
int op[1'000'001];
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=N;i>0;i--)
		cin >> op[i];
	
	int tmp=0;
	for(int i=1;i<=N;i++)
		switch(op[i]){
			case 1:
				dq.push_front(i);
				break;
			case 2:
				tmp=dq.front();
				dq.pop_front();
				dq.push_front(i);
				dq.push_front(tmp);
				break;
			case 3:
				dq.push_back(i);
				break;
		}
	
	for(auto a:dq)
		cout << a << ' ';
}
