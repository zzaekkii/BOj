#include <bits/stdc++.h>
using namespace std;
int r, c, a, b;

int main(){
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < a; j++){
			for (int k = 0; k < c; k++){
				for (int l = 0; l < b; l++)	{
					if ((i + k) % 2 == 0)
						cout << "X";
					else cout << ".";
				}
			}
			cout << '\n';
		}
	}
}
