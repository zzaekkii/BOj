#include <bits/stdc++.h>
using namespace std;
int A,B;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;

    while(1){
      B+=A;
      if(B>4){
          cout << "yt";
          break;
      }
      A+=B;
      if(A>4){
          cout << "yj";
          break;
      }
    }
}
