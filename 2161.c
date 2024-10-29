// 2161번 카드1 #큐 (근데 더 재밌게 풀 거임)
#include <stdio.h>
#include <stdlib.h>

// 재밌게 푸는 방법: 링크드 리스트를 직접 구현해서
// 큐처럼 동작하게 만들어주면 끄ㅌ~
typedef struct Node {
	int data;
	struct Node* link;
} Node;

int N;
Node* front, * rear; // 큐 앞/뒤 가리키는 애들.

int main() {
	scanf("%d", &N);

	// 큐(아무튼 큐임)에 카드 집어넣는 동작.
	for (int i = 1; i <= N; i++) {
		// 카드 한 장용 메모리 할당.
		Node* tmp = (Node*)malloc(sizeof(Node));
		// 카드 번호 넣기.
		tmp->data = i;
		tmp->link = NULL;

		// 큐에 암것도 없으면 얘가 머리임.
		if (!front) {
			front = tmp;
			rear = tmp;
		}// 아니면 마지막 애 뒤에 붙여주고 갈아치우기.
		else {
			rear->link = tmp;
			rear = tmp;
		}
	}

	// 동작을 수행해줄 차례.
	while (front != rear) {
		// 1. 제일 위 카드(front)를 버린다.
		// 근데 버리는 애는 출력 먼저해줘야 함.
		printf("%d ", front->data);

		// 2인자로 교체(1인자 메모리는 해제해줘야 함)
		Node* tmp = front;
		front = front->link;
		free(tmp);

		// 2. 걔(前front) 밑에 있던 카드를 밑(rear)에 넣는다.
		// 신규 1인자 밑으로 보내주기.
		rear->link = front;
		rear = front;

		front = front->link;
		rear->link = NULL;
	}

	// 한 마리 남았을 때, 마지막으로 출력.
	printf("%d", front->data);
	free(front);
}
