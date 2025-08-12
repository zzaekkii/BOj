#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
    char name[11];
    char address[11];
    char region[11];
}Person;

int cmp(const void* a, const void* b){
    const Person* p1=(const Person*)a;
    const Person* p2=(const Person*)b;
    return strcmp(p2->name,p1->name);
}

struct Person people[10];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", people[i].name, people[i].address, people[i].region);
    }
    
    qsort(people,n,sizeof(Person),cmp);

    printf("name %s\n",people[0].name);
    printf("addr %s\n",people[0].address);
    printf("city %s",people[0].region);
}