#include <stdio.h>
#define max(a, b) (((a)>(b))?(a):(b))

int N;
int arr[500001];

int main(){
    scanf("%d", &N);
	
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	
	int inc=1, dec=1, ans=1;
	for(int i=0;i<N-1;i++) {
		if(arr[i]<arr[i+1]){
			dec=1, inc++;
			ans=max(ans,inc);
		}
		else if(arr[i]>arr[i+1]){
			inc=1, dec++;
			ans=max(ans,dec);
		}
	}
	
	printf("%d", ans);
}