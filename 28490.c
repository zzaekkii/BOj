mx;main(N,H,W){
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&H,&W);
        mx<H*W?mx=H*W:mx;
    }
    printf("%d",mx);
}
