# [Platinum II] Typo - 17880 

[문제 링크](https://www.acmicpc.net/problem/17880) 

### 성능 요약

메모리: 448460 KB, 시간: 5680 ms

### 분류

자료 구조, 트리, 트라이

### 제출 일자

2026년 1월 21일 02:48:13

### 문제 설명

<p>It is now far into the future and human civilization is ancient history. Archaeologists from a distant planet have recently discovered Earth. Among many other things, they want to decipher the English language.</p>

<p>They have collected many printed documents to form a dictionary, but are aware that sometimes words are not spelled correctly (typos are a universal problem). They want to classify each word in the dictionary as either correct or a typo. Naïvely, they do this using a simple rule: a typo is any word in the dictionary such that deleting a single character from that word produces another word in the dictionary.</p>

<p>Help these alien archaeologists out! Given a dictionary of words, determine which words are typos. That is, which words result in another word in the dictionary after deleting a single character.</p>

<p>For example if our dictionary is {<code>hoose</code>, <code>hose</code>, <code>nose</code>, <code>noises</code>}. Then <code>hoose</code> is a typo because we can obtain <code>hose</code> by deleting a single ’<code>o</code>’ from <code>hoose</code>. But <code>noises</code> is not a typo because deleting any single character does not result in another word in the dictionary.</p>

<p>However, if our dictionary is {<code>hoose</code>, <code>hose</code>, <code>nose</code>, <code>noises</code>, <code>noise</code>} then the typos are <code>hoose</code>, <code>noises</code>, and <code>noise</code>.</p>

### 입력 

 <p>The first line of input contains a single integer n, indicating the number of words in the dictionary.</p>

<p>The next n lines describe the dictionary. The i<sup>th</sup> of which contains the i<sup>th</sup> word in the dictionary. Each word consists only of lowercase English letters. All words are unique.</p>

<p>The total length of all strings is at most 1 000 000.</p>

### 출력 

 <p>Display the words that are typos in the dictionary. These should be output in the same order they appear in the input. If there are no typos, simply display the phrase NO TYPOS.</p>

