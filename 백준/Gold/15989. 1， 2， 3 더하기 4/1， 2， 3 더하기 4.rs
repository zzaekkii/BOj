use std::io::{self, Read, Write};

const MAX: usize = 10_000;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let mut dp = vec![0usize; MAX + 1];
    dp[0] = 1;
    for i in 1..=3 {
        for j in i..=MAX {
            dp[j] += dp[j - i];
        }
    }

    let t: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        writeln!(out, "{}", dp[n]).unwrap();
    }
}
