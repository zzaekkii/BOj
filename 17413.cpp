#include <bits/stdc++.h>
using namespace std;
string S;
stack<char> st;

void print(){
    while(!st.empty()){
		cout << st.top();
		st.pop();
	}
}

int main(){
    getline(cin,S);
    
    for(int i=0;i<S.size();i++){
        if(S[i]=='<'){
            print();
            while(1){
				cout << S[i];
                if(S[i]=='>')break;
                i++;
            }
        }
        else if(S[i]==' '){
			print();
            cout << ' ';
        }
        else st.push(S[i]);
    }
    print();
}
