#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 9
#define MAX_ELEMENTS 20000
#define MAX_BOUND 100000 // 어차피 99999 초과로는 불가능.

typedef struct {
    int data[MAX_ELEMENTS];
    int size;
} NumSet;

NumSet dp[MAX_COUNT];

int contains(NumSet* set, int val){
    for(int i=0;i<set->size;i++)
        if(set->data[i]==val)return 1;
    
    return 0;
}

void insert(NumSet* set, int val){
    if(val>-MAX_BOUND&&val<MAX_BOUND){
        if(!contains(set,val))
            set->data[set->size++]=val;
    }
}

int solution(int N, int number) {
    if(N==number)return 1;
    
    for(int i=1;i<MAX_COUNT;i++){
        int concat=0;
        
        for(int j=0;j<i;j++)
            concat=concat*10+N;
        insert(&dp[i],concat);
        
        for(int j=1;j<i;j++){
            for(int a=0;a<dp[j].size;a++){
                for(int b=0;b<dp[i-j].size;b++){
                    int x=dp[j].data[a];
                    int y=dp[i-j].data[b];
                    
                    insert(&dp[i],x+y);
                    insert(&dp[i],x-y);
                    insert(&dp[i],x*y);
                    if(y!=0)insert(&dp[i],x/y);
                }
            }
        }
        
        if(contains(&dp[i],number))
            return i;
    }
    
    return -1;
}