#include <bits/stdc++.h>
using namespace std;

int arr[1000000]; // 입력 배열 
vector<int> v; // 압축 배열 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, i;
    cin >> N;
    
    for(i=0;i<N;i++){
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	
	sort(v.begin(),v.end()); // 오름차순 정렬 - 인덱스가 곧 개수 
    v.erase(unique(v.begin(),v.end()),v.end()); // 중복 요소 제거 
    
    for(i=0;i<N;i++) // 추출한 이터레이터에서 주솟 값 빼줌 -> 인덱스만 남음. 
    	cout << lower_bound(v.begin(),v.end(),arr[i])-v.begin() << " ";
}