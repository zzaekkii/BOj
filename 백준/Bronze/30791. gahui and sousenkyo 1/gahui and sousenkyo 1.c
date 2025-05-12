#include <stdio.h>

int arr[5];
int cnt;

int main(){
    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);
    
	for(int i=1;i<5;i++)
		if(arr[0]-arr[i]<=1000)cnt++;
    
    printf("%d",cnt);
}