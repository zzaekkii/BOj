#include <bits/stdc++.h>
using namespace std;
int arr[3];

bool desc(int a, int b){ // �������� compare 
  return a > b; 
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<3;i++) cin >> arr[i];
        
    sort(arr,arr+3,desc);
    
    int sum = arr[1]+arr[2];
    
    if(arr[0]*2==sum) cout << arr[0]*3; // ���ﰢ 
    else if(arr[0]<sum) cout << arr[0]+sum; // �״�� 
    else cout << sum*2-1; // ū �� ���� ���̱� 
}
