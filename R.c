A[1001];c;main(N,i,T){scanf("%d",&N);
for(i=0;i<N;i++)scanf("%d",&A[i]);
while(N--){
scanf("%d",&T);
if(A[i-N-1]<=T)c++;
}
printf("%d",c);}
