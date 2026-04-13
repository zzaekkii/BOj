use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();
    let mut out = io::BufWriter::new(io::stdout().lock());

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut dp = vec![false; n + 1];
    dp[1] = true;

    for _ in 0..m {
        for i in 1..=n {
            let x: usize = iter.next().unwrap().parse().unwrap();

            if x == 0 {
                dp[i] = false;
                continue;
            }

            if dp[i] || dp[i - 1] {
                dp[i] = true;
            } else {
                dp[i] = false;
            }
        }
    }

    writeln!(out, "{}", if dp[n] { "Yes" } else { "No" }).unwrap();
}
