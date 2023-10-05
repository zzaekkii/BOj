#include <bits/stdc++.h>
using namespace std;
int X, Y, xw, yw, xh, yh;

int main(){
	cin >> X >> Y;

	xw = (X - 1) / 4;
	yw = (Y - 1) / 4;

	xh = (X-1) % 4;
	yh = (Y-1) % 4;

	cout << abs(xw - yw) + abs(xh - yh);
}
