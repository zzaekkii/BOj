#include <bits/stdc++.h>
using namespace std;

struct MEMO{long long url;char pw[21];} memo[100001];

int N,M;
char buf[6'300'015];
int p;

int write_idx=0;
char write_buf[2'100'000];

void writeWord(const char* s){
    while(*s)write_buf[write_idx++]=*s++;
    write_buf[write_idx++]='\n';
}

int main(){
    fread(buf,1,6'300'015,stdin);
    while(buf[p]!=' ')N=N*10+buf[p++]-48;
    p++;
    while(buf[p]!='\n')M=M*10+buf[p++]-48;
    p++;
    
    for(int i=0;i<N;i++){
        while(buf[p]!=' ')memo[i].url=memo[i].url*255+buf[p++];
        p++;
        int idx=0;
        while(buf[p]!='\n')memo[i].pw[idx++]=buf[p++];
        p++;
    }
    
    sort(memo,memo+N,[&](const MEMO&a,const MEMO&b){return a.url<b.url;});
    
    while(M--){
        long long key=0;
        while(buf[p]!='\n')key=key*255+buf[p++];
        p++;
        int st=0,en=N-1;
        while(st<=en){
            int md=(st+en)/2;
            if(key==memo[md].url){
                writeWord(memo[md].pw);
                break;
            }
            if(key<memo[md].url)en=md-1;
            else st=md+1;
        }
    }
    
    fwrite(write_buf,1,write_idx,stdout);
}