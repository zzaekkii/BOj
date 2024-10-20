#include <stdio.h>

int N, K;
char S[500001];

int main() {
	scanf("%d %d ", &N, &K);

    scanf("%s",S);
    
    if ((N - K) % 2){
        for(int i=K-1;i<N;i++)
            printf("%c", S[i]);
        for(int i=0;i<K-1;i++)
            printf("%c", S[i]);
    }
    else {
		for (int i = K - 1; i < N; i++)
			printf("%c", S[i]);
		for (int i = K - 2; i >= 0; i--)
			printf("%c", S[i]);
	}
}
