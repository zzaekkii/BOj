use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let k: i64 = iter.next().unwrap().parse().unwrap();

    let mut energy = vec![0i64; n];
    for i in 0..n {
        energy[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut dp = vec![false; n];
    dp[0] = true;

    for i in 1..n {
        for j in 0..i {
            let cost = (i as i64 - j as i64) * (1 + (energy[j] - energy[i]).abs());
            if dp[j] && cost <= k {
                dp[i] = true;
                break;
            }
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", if dp[n - 1] { "YES" } else { "NO" }).unwrap();
}
