#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char num[101];
}letter;


int N;
char S[101];
letter box[5001];
int cnt;

int cmp(const void *a, const void *b) {
    int lenA=strlen(((letter*)a)->num);
    int lenB=strlen(((letter*)b)->num);
    if(lenA==lenB)return strcmp(((letter*)a)->num, ((letter*)b)->num);
    return lenA-lenB;
}

int main(){
    scanf("%d ",&N);
    
    for(int i=0;i<N;i++){
        scanf("%s",S);
        int st=0,en=0;
        for(int j=0;S[j];j++){
            if(97<=S[j]&&S[j]<=122){ // meet alpha.
                if(st!=en){ // there was num.
                    en--;
                    for(int k=st;k<en;k++) // rm fst 0.
                        if(S[k]!=48)break;
                        else st++;
                    strncpy(box[cnt++].num,S+st,en-st+1); // save num.
                }
                st=en=j+1;
                continue;
            }
            else en++; // num length++;
        }
        if(st!=en&&en==strlen(S)){
            en--;
            for(int k=st;k<en;k++) // rm fst 0.
                if(S[k]!=48)break;
                else st++;
            strncpy(box[cnt++].num,S+st,en-st+1); // save num.
        }
    }
    qsort(box,cnt,sizeof(letter),cmp);
    for(int i=0;i<cnt;i++)
        puts(box[i].num);
}
