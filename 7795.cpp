#include <bits/stdc++.h>
using namespace std;

int T, N, M, tmp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    using namespace std;
	cin >> T;
	
	while(T--){
		vector<int> a;
		vector<int> b;
		cin >> N >> M;
		
		for(int i=0;i<N;i++){
			cin >> tmp;
			a.push_back(tmp);
		}
		sort(a.begin(),a.end());
		
		for(int i=0;i<M;i++){			
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(b.begin(),b.end());
		
		int cnt=0;
		
		for (int i = 0; i < N; i++) {
			int left = 0, right = M;
			while (left + 1 < right) {
				int mid = (left + right) / 2;
				if (a[i] > b[mid]) left = mid;
				else right = mid;
			}
			cnt += left;
			if (a[i] > b[left]) cnt++;
		}
		cout << cnt << "\n";
	}
}
