#include <stdio.h>
#include <string.h>
char S[9];
int mem[32];
int pc, acc; // pc(5bit/32), acc(8bit/256)

// 오늘은 내가 심심함
int main() {
	while (1) {
		memset(mem, 0, 128);
		for (int i = 0; i < 32; i++) {
			if (!(~scanf("%s ", S))) return 0; // EOF
			for (int j = 0; j < 8; j++) {
				mem[i] = mem[i] * 2 + S[j]-48;
			}
		}

		pc = acc = 0;
		while (1) {
			int op = mem[pc] / 32; // operator
			int val = mem[pc] % 32; // operand
			pc=(pc+1)%32;

			if (op == 7) // HLT
				break;

			switch (op) {
			case 0: // STA x
				mem[val] = acc;
				break;
			case 1: // LDA x
				acc = mem[val];
				break;
			case 2: // BEQ x
				if (!acc)pc = val;
				break;
			case 3: // NOP
				break;
			case 4: // DEC
				acc = (acc + 255) % 256;
				break;
			case 5: // INC
				acc = (acc + 1) % 256;
				break;
			case 6: // JMP x
				pc = val;
				break;
			}
		}

		for (int i = 7; i >= 0; i--)
			printf("%d", (acc >> i) & 1); // & 0000 0001
		puts("");
	}
}
