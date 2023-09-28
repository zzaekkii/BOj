#include <stdio.h>
int N, F;
int ans;

int main() {
	scanf("%d%d",&N,&F);
	N /= 100;
	N *= 100;
	
	while((N+ans)%F&&ans<100)ans++;
	
	if(ans<10)printf("0%d", ans);
	else printf("%d", ans);
}
