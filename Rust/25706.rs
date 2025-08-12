use std::io::{self, Read, Write};

fn main(){
    // 입력 (N, 배열)
    let (n, board) = inputs();

    // DP
    let mut dp = vec![0usize; n];
    
    for i in (0..=n-1).rev(){
        if i + board[i] + 1 < n{
            dp[i] = dp[i + board[i] + 1] + 1;
        }
        else {
            dp[i] = 1;
        }
    }

    // 정답 출력
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    for i in dp {
        write!(out, "{}", i).unwrap();

        if i > 0 {
            write!(out, " ").unwrap();
        }
    }

    writeln!(out).unwrap();
}

fn inputs() -> (usize, Vec<usize>){
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let mut board  = vec![0usize; n];
    for i in 0..n {
        board[i] = it.next().unwrap().parse().unwrap();
    }

    (n, board)
}
