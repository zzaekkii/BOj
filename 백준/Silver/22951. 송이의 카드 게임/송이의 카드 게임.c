#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int own, val;
	struct Node* prev, *nxt;
}Node;

int N, K, T;
Node *head=0, *last=0;

int main(){
    scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
		for(int j=0;j<K;j++){
			scanf("%d",&T);
			
			Node* node=(Node*)malloc(sizeof(Node));
            *node=(Node){i,T,0,0};
			
			if(!head){
				head=node;
			}
			else{
				last->nxt=node;
				node->prev=last;
			}
			last=node;
		}
	head->prev=last;
	last->nxt=head;
	
	Node* cur=head;
	
	while(cur->nxt!=cur){
		int x=cur->val;
		Node* tmp=cur;
		
		tmp->prev->nxt=tmp->nxt;
		tmp->nxt->prev=tmp->prev;
		
		for(int i=0;i<x;i++)
			cur=cur->nxt;
		
		free(tmp);
	}
	
    printf("%d %d",cur->own, cur->val);
}