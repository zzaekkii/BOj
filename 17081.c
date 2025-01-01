// 17081번 RPG Extreme - 플래티넘2 / #구현 #시뮬레이션
#include <stdio.h>
#include <string.h>
#define max(a, b) (((a)>(b))?(a):(b))
#define min(a, b) (((a)<(b))?(a):(b))
#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)
#define ACC_CNT 7
#define NECESSARY_EXPR 5 // 레벨업에 필요한 경험치 -> 5 * 현재 레벨.
#define HR_RECOVERY 3 // HR 장신구 보유 시, 체력 회복량 3

const char* command_dir[] = { 'L', 'R', 'U', 'D' }; // 커맨드 종류 목록.
const char* accessories[] = { "HR", "RE", "CO", "EX", "DX", "HU", "CU" }; // 장신구 목록.
enum Ending { KILL_BOSS, MONSTER, SPIKE_TRAP, COMMAND_END }; // 게임 끝 원인 목록 + 사망 원인에도 사용.

int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 }; // 방향(L,R,U,D)에 따른 좌표 변화량.

typedef struct Hero {
	int x, y; // 현재 위치.
	int cur_hp; // 현재 체력.
	int hp, atk, def; // 체력, 공격력, 방어력.
	int expr, lv; // 경험치, 레벨.
	int weapon, armor; // 무기, 방어구. // 0이면 미착용.

	int accessories_cnt; // 장신구 개수.
	_Bool accesorries[7]; // 장신구 보유 여부 목록.
	// _Bool hr, re, co, ex, dx, hu, cu; // 장신구 착용시 true.
}Hero;

typedef struct Monster {
	int x, y; // 위치.
	int cur_hp; // 현재 체력.
	char name[11]; // 이름.
	int atk, def, hp; // 공격력, 방어력, 체력.
	int expr; // 처치 보상 경험치.
}Monster;

typedef struct Item {
	char type; // 아이템 타입{W, A, O}
	int stat; // 무기 및 방어구 스탯.
	char acc_name[3]; // 장신구 이름.
}Item;

int N, M; // 맵 크기.
char board[101][101]; // 맵.
char command[5001]; // 이동 명령.
Monster monster[10000]; // 몬스터 목록.
Item item[10000]; // 아이템 목록.
int idx_board[101][101]; // 해당 몬스터/아이템의 인덱스를 가리키는 맵.

int monster_cnt, item_cnt; // 몬스터(보스 포함) 수, 아이템 박스 수.
int start_x, start_y; // 주인공 시작 위치(부활 고려).
int turn; // 턴 수.

// 주인공 초기화.
Hero H = {
	.x = 0, .y = 0, // 현재 위치는 나중에 입력값 사용.
	.cur_hp = 20, // 현재 체력.
	.hp = 20, .atk = 2, .def = 2, // 기본 체력, 공격력, 방어력.
	.expr = 0, .lv = 1, // 기본 경험치, 레벨.
	.weapon = 0, .armor = 0, .accessories_cnt = 0, // 무기, 방어구, 장신구 미착용.
	// 장신구 보유 여부 목록은 0(FALSE)으로 자동 초기화.
};

// 이동 명령 올바른지 판단.
_Bool CanGo(int x, int y) {
	// 맵 범위 내에 있고, 벽이 아니면 다 갈 수 있음.
	if (0 <= x && x < N && 0 <= y && y < M)
		if (board[x][y] != '#') return 1;
	return 0;
}

// 해당 장신구의 인덱스를 넘겨줌(보유 여부 조회용)
int GetAccIdx(char* accName) {
	for (int i = 0; i < ACC_CNT; i++)
		if (!strcmp(accessories[i], accName))
			return i;

	// 그럴 일 없겠지만, 장신구 이름 입력 오류 대비.
	return -1;
}

// 게임 엔딩 출력.
void PrintEnding(enum Ending ending, char* name) {
	// 주인공 위치 표시 - 코드 의존적인 부분이지만, 현재는 2가지이기에 결정.
	// 확장 시엔 주인공 위치 표시를 계속 하든,
	// 주인공이 표시되는 엔딩의 경우를 미리 지정해두고 판별하면 됨.
	if (ending == KILL_BOSS || ending == COMMAND_END)
		board[H.x][H.y] = '@';

	// 커맨드 입력 종료로 끝난 게 아니라면 턴을 증가시켜 줘야 함.
	if (ending != COMMAND_END)
		turn++;

	// 맵 출력.
	for (int i = 0; i < N; i++)
		puts(board[i]);

	// 진행된 턴 수.
	printf("Passed Turns : %d\n", turn);

	// 종료 시점 주인공 정보.
	printf("LV : %d\n", H.lv);
	printf("HP : %d/%d\n", H.cur_hp, H.hp);
	printf("ATT : %d+%d\n", H.atk, H.weapon);
	printf("DEF : %d+%d\n", H.def, H.armor);
	printf("EXP : %d/%d\n", H.expr, 5 * H.lv);

	// 게임 결과.
	switch (ending) {
	case KILL_BOSS: // 보스 처치.
		puts("YOU WIN!");
		break;
	case MONSTER: // 몬스터 또는 가시 함정에 의해 사망.
	case SPIKE_TRAP:
		printf("YOU HAVE BEEN KILLED BY %s..\n", name);
		break;
	case COMMAND_END: // 커맨드 끝.
		puts("Press any key to continue.");
		break;
	}

	exit(0);
}

// 사전 입력 데이터 종합.
void Input() {
	// 맵 크기.
	scanf("%d %d ", &N, &M);

	// 몬스터 및 아이템 목록 번호 가리키는 도감 초기화.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			idx_board[i][j] = -1;

	// 맵 구성.
	for (int i = 0; i < N; i++)
		gets(board[i]);

	// 몬스터 수, 아이템 수 췌크.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '&' || board[i][j] == 'M')
				monster_cnt++;

			if (board[i][j] == 'B')
				item_cnt++;

			// 용사 최초 위치 췌크.
			if (board[i][j] == '@') {
				start_x = i, start_y = j;
				H.x = i, H.y = j;
			}
		}

	// 이동 명령.
	gets(command);

	// 몬스터 정보,
	for (int i = 0; i < monster_cnt; i++) {
		// 위치(x, y), 이름, 공격력, 방어력, 체력, 처치 경험치.
		int monster_x = 0, monster_y = 0;
		scanf("%d %d ", &monster_x, &monster_y);
		monster[i].x = monster_x - 1, monster[i].y = monster_y - 1;
		scanf("%s %d %d %d %d", monster[i].name,
			&(monster[i].atk), &(monster[i].def), &(monster[i].hp), &(monster[i].expr));

		// 몬스터 현재 체력도 기본 체력으로 초기화.
		monster[i].cur_hp = monster[i].hp;

		// 몬스터 위치로 몬스터 판별 가능.
		idx_board[monster[i].x][monster[i].y] = i;
	}

	// 아이템 정보.
	for (int i = 0; i < item_cnt; i++) {
		int item_x, item_y; // 몬스터는 전투 중 회복될 수 있어서 위치가 필요하나, 아이템은 필요 없음.
		scanf("%d %d %c ", &item_x, &item_y, &(item[i].type));

		switch (item[i].type) {
		case 'W': // 무기.
			scanf("%d", &(item[i].stat));
			break;
		case 'A': // 방어구.
			scanf("%d", &(item[i].stat));
			break;
		case 'O': // 장신구.
			scanf("%s", item[i].acc_name);
			break;
		}

		idx_board[item_x - 1][item_y - 1] = i;
	}
}

// 레벨업.
void LevelUp() {
	// 현재 경험치 0으로 변경(레벨업 하고 남아도 버림)
	H.expr = 0;

	// 레벨 1 상승.
	H.lv++;

	// 체력 5 상승.
	H.hp += 5;

	// 공격력, 방어력 2 상승.
	H.atk += 2;
	H.def += 2;

	// 체력 풀피 회복.
	H.cur_hp = H.hp;
}

// 부활 <- 아이템 소모 + 최초 위치 + 몬스터 체력 회복.
void Revival(enum Ending die) {
	// 부활 아이템 RE는 1회 사용 후 소멸 처리.
	H.accesorries[GetAccIdx("RE")] = FALSE;
	H.accessories_cnt--; // 굳이 예외 처리는 하지 않았다.

	// 사망 원인별 대처.
	switch (die) {
		// 전투 중 사망한 거라면, 적 몬스터도 풀피 회복 처리.
	case MONSTER:
		monster[idx_board[H.x][H.y]].cur_hp = monster[idx_board[H.x][H.y]].hp;
		// 공통 처리. default 쓸 수도 있지만 명시적 표현.
	case SPIKE_TRAP:
		H.cur_hp = H.hp; // 풀피 회복.
		H.x = start_x, H.y = start_y; // 최초 위치로 이동.
		break;
	}
}

// 가시 함정을 밟음.
void Trap() {
	int dmg = 5;

	// DX 장신구가 있다면 가시 데미지 1로 적용.
	if (H.accesorries[GetAccIdx("DX")])
		dmg = 1;

	// 가시 데미지 적용(체력 0 이하는 모두 0)
	H.cur_hp = max(0, H.cur_hp - dmg);

	// 만약 이걸로 주인공 사망 시, 부활 or 게임 종료.
	if (H.cur_hp == 0) {
		// 부활 아이템 RE가 있다면 부활.
		if (H.accesorries[GetAccIdx("RE")])
			Revival(SPIKE_TRAP);
		// 그게 아니라면 게임 종료.
		else PrintEnding(SPIKE_TRAP, "SPIKE TRAP");
	}
}

// 아이템 박스 발견.
void GetItem() {
	// 발견한 아이템.
	Item cur_item = item[idx_board[H.x][H.y]];

	switch (cur_item.type) {
	case 'W': // 무기.
		H.weapon = cur_item.stat;
		break;
	case 'A': // 방어구도 무기와 마찬가지
		H.armor = cur_item.stat;
		break;
	case 'O': // 장신구.
		// 주인공이 착용한 장신구가 3개 이하일 시 착용 가능(최대 4개 제한)
		// + 착용하지 않은 장신구만 습득 가능.
		if (H.accessories_cnt < 4 && !H.accesorries[GetAccIdx(cur_item.acc_name)]) {
			H.accesorries[GetAccIdx(cur_item.acc_name)] = TRUE; // 장착.
			H.accessories_cnt++; // 장신구 보유 개수 증가.
		}
		break;
	}

	// 아이템 박스 자리는 열고나면 맵에 . 빈 칸으로 처리.
	board[H.x][H.y] = '.';
}

// 몬스터 및 보스와 전투.
void Fight() {
	// 조우한 몬스터.
	Monster* cur_monster = &monster[idx_board[H.x][H.y]];

	// 주인공 공격력(기본 공격 스탯 + 무기 스탯)
	int total_atk = H.atk + H.weapon;

	// 주인공 방어력(기본 방어 스탯 + 방어구 스탯)
	int total_def = H.def + H.armor;

	for (int round = 1; cur_monster->cur_hp > 0; round++) {
		// 보유 장신구에 따라 첫 라운드 효과 적용.
		int bonus_dmg = 0;
		if (round == 1) {
			// CO 보유 시, 첫 공격 2배. 
			if (H.accesorries[GetAccIdx("CO")]) {
				bonus_dmg = total_atk;
				// CO + DX 보유 시, 첫 공격 3배.
				if (H.accesorries[GetAccIdx("DX")])
					bonus_dmg += total_atk;
			}

			// HU 보유 시, 보스와 조우하면 풀피 회복 + 보스 첫 공격 무효.
			if (board[H.x][H.y] == 'M' && H.accesorries[GetAccIdx("HU")]) {
				H.cur_hp = H.hp; // 풀피 회복.
				cur_monster->cur_hp -= max(1, total_atk + bonus_dmg - cur_monster->def);
				bonus_dmg = 0;
				continue; // 보스 첫 공격 무효.
			}
		}

		// 주인공 선공.
		cur_monster->cur_hp -= max(1, total_atk + bonus_dmg - cur_monster->def);
		bonus_dmg = 0;

		// 몬스터 사망 시, 전투 종료.
		if (cur_monster->cur_hp <= 0) break;

		// 몬스터 공격.
		H.cur_hp = max(0, H.cur_hp - max(1, cur_monster->atk - total_def));

		// 사망 시, 부활 or 게임 종료.
		if (H.cur_hp == 0) {
			// 부활 아이템 RE 보유 시, 부활.
			if (H.accesorries[GetAccIdx("RE")]) {
				Revival(MONSTER);
				return;
			}
			// 사망 -> 게임 종료.
			else PrintEnding(MONSTER, cur_monster->name);
		}
	}

	// EX 보유 시, 몬스터 처치 경험치 1.2배(소수점 아래 버림)
	if (H.accesorries[GetAccIdx("EX")])
		H.expr += cur_monster->expr * 1.2;
	else H.expr += cur_monster->expr;

	// 레벨업 가능하면 레벨업.
	if (H.expr >= H.lv * NECESSARY_EXPR)
		LevelUp();

	// HR 보유 시, 전투 승리 후 체력 3 회복(최대 체력까지만)
	if (H.accesorries[GetAccIdx("HR")])
		H.cur_hp = min(H.hp, H.cur_hp + HR_RECOVERY);

	// 보스였다면 게임 끝
	if (board[H.x][H.y] == 'M')
		PrintEnding(KILL_BOSS, cur_monster->name);

	// 몬스터 위치 . 빈 칸으로 업데이트.
	board[H.x][H.y] = '.';

	// printf("몬스터 %s와 싸워 이겼다!\n", cur_monster->name);

}

// 이동 명령대로 게임 진행.
void Play() {
	// 이동 시 이전 위치 @ 사라지고 빈칸 혹은 가시.
	// 이것에 대해 결과에서만 주인공 위치를 표시하도록 선택.
	// 이로써 맵 상에서 주인공 위치에 대해 연산하지 않아도 됨.
	board[H.x][H.y] = '.'; // 최초 위치 . 빈 칸으로 업데이트.

	for (; command[turn]; turn++) {
		// 이동 명령 방향별로 변화량 업데이트.
		int dir = 0;
		for (; command_dir[dir] != command[turn]; dir++);
		int nx = H.x + dx[dir], ny = H.y + dy[dir];

		// 벽을 만나거나 맵을 벗어나지 않는다면 레츠고.
		if (CanGo(nx, ny)) {
			H.x = nx, H.y = ny;
			switch (board[nx][ny]) {
			case '.': // 빈 칸.
				// puts("빈 칸!");
				break;
			case 'B': // 아이템 상자.
				// puts("아이템 발견!");
				GetItem();
				break;
			case '^': // 가시 함정.
				// puts("가시 함정!");
				Trap();
				break;
			case '&': // 몬스터 조우.
			case 'M': // 보스 몬스터 조우.
				// puts("몬스터 발견!");
				Fight();
				break;
			}
		}
		else {
			// puts("갈 수 없다!");
			// 지금 위치에 가시 함정이 있다면 한번 더 함정 데미지.
			if (board[H.x][H.y] == '^')
				Trap();
		}

		// printf("현재 레벨: %d, 체력: %d/%d, 공격력: %d(+%d), 방어력: %d(+%d), 경험치: %d\n", H.lv, H.cur_hp, H.hp, H.atk, H.weapon, H.def, H.armor, H.expr);
	}
	PrintEnding(COMMAND_END, NULL);
}

int main() {
	Input();
	Play();
}
