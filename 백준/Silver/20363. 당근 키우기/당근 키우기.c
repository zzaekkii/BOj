#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int X, Y;

int main(){
    scanf("%d %d", &X, &Y);
	printf("%d", X+Y+min(X,Y)/10);
}