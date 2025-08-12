use std::io::{self, Read, Write};
use std::cmp::min;

fn main(){
    // 입력 (N, M, 2차원 배열)
    let (n, m, board) = inputs();

    // DP
    let mut dp = vec![vec![u32::MAX / 4; m]; n];
    dp[0][0] = 0;

    for i in 0..n{
        for j in 0..m{
            for dx in 1..=board[i][j] as usize{
                if in_range(i+dx, j, n, m){
                    dp[i+dx][j] = min(dp[i+dx][j], dp[i][j]+1);
                }
            }

            for dy in 1..=board[i][j] as usize{
                if in_range(i, j+dy, n, m){
                    dp[i][j+dy] = min(dp[i][j+dy], dp[i][j]+1);
                }
            }
        }
    }

    // 정답 출력
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    writeln!(out, "{}", dp[n-1][m-1]);
}

fn in_range(x: usize, y: usize, n: usize, m: usize) -> bool{
    x<n && y<m
}

fn inputs() -> (usize, usize, Vec<Vec<u16>>){
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    let mut board = vec![vec![0u16; m]; n];
    for i in 0..n{
        for j in 0..m{
            board[i][j] = it.next().unwrap().parse().unwrap();
        }
    }

    (n, m, board)
}