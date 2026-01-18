# [Platinum III] XOR - 29441 

[문제 링크](https://www.acmicpc.net/problem/29441) 

### 성능 요약

메모리: 63696 KB, 시간: 84 ms

### 분류

자료 구조, 트리, 트라이

### 제출 일자

2026년 1월 19일 03:22:09

### 문제 설명

<p>Today Paul and Andrew discovered a new operation, <code>XOR</code> of two numbers.</p>

<p>Let us remind you that <code>XOR</code>, or <em>exclusive OR</em>, is a binary operation which is applied to two integer numbers bitwise. For each bit position, if the bits in the arguments are equal, the resulting bit is <code>0</code>, otherwise <code>1</code>. For example, 3 <code>XOR</code> 5 $=$ 6, because $3_{10} = 011_2$, $5_{10} = 101_2$, so if we apply the operation, the second and the third bits are set to <code>1</code>, bit the first bit is set to 0, so we get $110_{2} = 6_{10}$.</p>

<p>Paul and Andrew liked this operation so much that they invented a game. First, Paul writes $n$ integer numbers $a_i$. Second, Andrew writes $m$ integers $b_j$. After that, Paul finds for each $b_j$ such $k$ that $a_k$ <code>XOR</code> $b_j$ is maximal.</p>

<p>The only problem is that Paul is not very fast in finding these numbers. Help him!</p>

### 입력 

 <p>The first line of the input contains one integer $n$ ($1 \le n \le 100,000$) --- how many numbers Paul wrote. The second line contains Paul's numbers $a_i$ ($0 \le a_i \le 10^9$). All $a_i$ are different.</p>

<p>The third line contains an integer $m$ ($1 \le m \le 100,000$) --- how many numbers Andrew wrote. The fourth line contains Andrew's numbers $b_j$ ($0 \le b_j \le 10^9$).</p>

### 출력 

 <p>Output $m$ numbers: for each $b_j$, output such $a_k$ that $a_k$ <code>XOR</code> $b_j$ is maximal.</p>

