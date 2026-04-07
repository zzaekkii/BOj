use std::{
    io::{self, Read, Write},
    vec,
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();

    let mut board = vec![vec![true; n]; n];
    for r in 0..n {
        for c in 0..n {
            let b: u8 = iter.next().unwrap().parse().unwrap();
            board[r][c] = if b == 0 { true } else { false };
        }
    }

    // 가로, 세로, 대각
    let mut dp = vec![vec![[0usize; 3]; n]; n];
    dp[0][1][0] = 1;

    for r in 0..n {
        for c in 2..n {
            if !board[r][c] {
                continue;
            }

            dp[r][c][0] = dp[r][c - 1][0] + dp[r][c - 1][2];

            if r > 0 {
                dp[r][c][1] = dp[r - 1][c][1] + dp[r - 1][c][2];
            }

            if r > 0 && board[r - 1][c] && board[r][c - 1] {
                dp[r][c][2] = dp[r - 1][c - 1][0] + dp[r - 1][c - 1][1] + dp[r - 1][c - 1][2];
            }
        }
    }

    let ans = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", ans).unwrap();
}
