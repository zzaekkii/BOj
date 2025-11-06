#include <stdio.h>

int N;

int main(){
    scanf("%d",&N);
    int h=5*N, w=5*N;
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int r=i/N, c=j/N;
            
            if((c==0||c==2||c==4)
              ||(r==0&&c==1)
              ||(r==4&&c==3))
                putchar('@');
            else putchar(' ');
        }
        
        puts("");
    }
}
