#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    int x, y;
} Point;

typedef struct Node{
    Point value;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

Queue initQueue();
int isEmpty(Queue* q);
void push(Queue* q, Point value);
Point pop(Queue* q);

int N, M;
int board[100][100]; // 시작점은 (0,0) 도착지는 (N-1,M-1)
int vis[100][100];
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};

int isInRange(int x, int y){
    if(x>=0&&x<N&&y>=0&&y<M) return 1;
    return 0;
}

void bfs(int x, int y){
    Queue Q=initQueue();
    push(&Q,(Point){x,y});
    vis[x][y]=1;

    while(!isEmpty(&Q)){
        Point cur=pop(&Q);
        int curX=cur.x;
        int curY=cur.y;

        for(int dir=0;dir<4;dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];

            if(isInRange(nx,ny)&&board[nx][ny]==1&&!vis[nx][ny]){
                push(&Q,(Point){nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&board[i][j]); // 0이면 뱀, 1이면 길.
    
    bfs(0,0);

    printf("%d",vis[N-1][M-1]);
}

Queue initQueue(){
    Queue q;
    q.front=q.rear=0;
    return q;
}

int isEmpty(Queue* q){
    return q->front==0;
}

// 메모리 터지는 건 고려하지 않음.
void push(Queue* q, Point value){
    Node* newNode=malloc(sizeof(Node));

    newNode->value=value;
    newNode->next=0;

    if(isEmpty(q)){
        q->front=q->rear=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

// empty는 고려하지 않음.
Point pop(Queue* q){
    Node* temp=q->front;
    Point value=temp->value;

    q->front=q->front->next;
    if(q->front==0)
        q->rear=0;
    
    free(temp);
    return value;
}