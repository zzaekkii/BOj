#include <stdio.h>
#include <stdlib.h>

int K;

typedef struct node {
	int data;
	struct node* left, * right;
}node;

node* new(int num){
	node * n = (node*)malloc(sizeof(node));
	n->data = num;
	n->left = n->right = NULL;
	return n;
}

node* search(node* n, int num) {
	if (n->data > num) {
		if (n->left == NULL)return n;
		else return search(n->left, num);
	}
	if (n->data < num) {
		if (n->right == NULL)return n;
		else return search(n->right, num);
	}
}

void set(node* n, int num) {
	if (n->data > num) n->left = new(num);
	if (n->data < num) n->right = new(num);
}

void post(node* n) {
	if (n != NULL) {
		post(n->left);
		post(n->right);
		printf("%d\n", n->data);
	}
}

int main() {
	node* n = new(NULL);
	node* v;
	while (scanf("%d", &K) != EOF) {
		if (n->data == NULL)n = new(K);
		else {
			v = search(n, K);
			set(v, K);
		}
	}
	post(n);
}
