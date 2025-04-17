#include <stdio.h>

typedef struct Point{
    int x, y;
}Point;

Point p[3];

int main(){
    for(int i=0;i<3;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    
    int ccw=(p[1].x-p[0].x)*(p[2].y-p[0].y)-(p[1].y-p[0].y)*(p[2].x-p[0].x);
    puts(!ccw?"0":ccw>0?"1":"-1");
}