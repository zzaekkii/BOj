#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int dfs(int hp, int count, int** dungeons, size_t dungeon_count, _Bool visited[]) {
    int best = count;
    
    for (size_t i = 0; i < dungeon_count; i++) {
        int required = dungeons[i][0];
        int cost = dungeons[i][1];

        if (visited[i]) {
            continue;
        }

        if (hp < required) {
            continue;
        }

        visited[i] = 1;
        int result = dfs(hp - cost, count + 1, dungeons, dungeon_count, visited);
        best = max(best, result);
        visited[i] = 0;
    }
    
    return best;
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    _Bool visited[8] = {0};
    return dfs(k, 0, dungeons, dungeons_rows, visited);
}