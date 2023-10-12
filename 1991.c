#include <stdio.h>
#include <stdlib.h>

int R;
char D, G, T;

typedef struct node{
	char data;
	struct node* left, * right;
}node;

node* new(char c){
	node * n = (node*)malloc(sizeof(node));
	n->data = c;
	n->left = n->right = NULL;
	return n;
}

node* search(node* n, char c) {
	if (n != NULL)
		if (n->data == c)
			return n;
		else {
			node* v = search(n->left, c);
			if (v != NULL)
				return v;
			else
				return search(n->right, c);
		}
	else
		return NULL;
}

void set(node* n, char d, char g, char t) {
	n->data = d;
	if (g != 46) n->left = new(g);
	if (t != 46) n->right = new(t);
}

void pre(node* n) {
	if (n != NULL) {
		printf("%c", n->data);
		pre(n->left);
		pre(n->right);
	}
}
void in(node* n) {
	if (n != NULL) {
		in(n->left);
		printf("%c", n->data);
		in(n->right);
	}
}
void post(node* n) {
	if (n != NULL) {
		post(n->left);
		post(n->right);
		printf("%c", n->data);
	}
}

int main(){
	scanf("%d ", &R);
	node* n = new(NULL);
	node* v;
	while(R--){
		scanf("%c %c %c ", &D, &G, &T);
		v = search(n, D);
		if (v != NULL) set(v, D, G, T);
		else set(n, D, G, T);
	}
	pre(n);
	puts("");
	in(n);
	puts("");
	post(n);
}
