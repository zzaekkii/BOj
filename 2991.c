#include <stdio.h>
int A,B,C,D;
int arr[3];
int ans[3];
int main(){
    scanf("%d%d%d%d",&A,&B,&C,&D);
    for(int i=0;i<3;i++){
        scanf("%d",&arr[i]);
        int dog1=arr[i]%(A+B) ;
        int dog2=arr[i]%(C+D);
        if(dog1<=A&&dog1)ans[i]++;
        if(dog2<=C&&dog2)ans[i]++;
    }
    for(int i=0;i<3;i++)printf("%d\n",ans[i]);
}
