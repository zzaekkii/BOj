#include <bits/stdc++.h>
using namespace std;
int A, B, C;

int w[21][21][21];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            for(int k=0;k<21;k++)
                if(i==0||j==0||k==0)w[i][j][k]=1;
                else if(i<j&&j<k)w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                else w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];

    while(1){
        cin >> A >> B >> C;
        if(A==-1&&B==-1&&C==-1)break;
        cout << "w(" << A << ", " << B << ", " << C << ") = ";
        if(A<=0||B<=0||C<=0)cout << "1\n";
        else if(A>20||B>20||C>20)cout << w[20][20][20] << '\n';
        else cout << w[A][B][C] << '\n';
    }
}
