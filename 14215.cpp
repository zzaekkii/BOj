#include <bits/stdc++.h>
using namespace std;
int arr[3];

bool desc(int a, int b){ // 내림차순 compare 
  return a > b; 
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<3;i++) cin >> arr[i];
        
    sort(arr,arr+3,desc);
    
    int sum = arr[1]+arr[2];
    
    if(arr[0]*2==sum) cout << arr[0]*3; // 정삼각 
    else if(arr[0]<sum) cout << arr[0]+sum; // 그대로 
    else cout << sum*2-1; // 큰 변 길이 줄이기 
}
