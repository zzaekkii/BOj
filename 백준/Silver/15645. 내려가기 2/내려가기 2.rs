use std::{io::{self, Read, Write}, usize};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = vec![0usize; 3];
    for i in 0..3 {
        arr[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut max_dp = [arr[0], arr[1], arr[2]];
    let mut min_dp = [arr[0], arr[1], arr[2]];

    for _ in 1..n {
        for i in 0..3 {
            arr[i] = iter.next().unwrap().parse().unwrap();
        }

        let prev_max = max_dp;
        let prev_min = min_dp;

        max_dp[0] = arr[0] + prev_max[0].max(prev_max[1]);
        max_dp[1] = arr[1] + prev_max[0].max(prev_max[1]).max(prev_max[2]);
        max_dp[2] = arr[2] + prev_max[1].max(prev_max[2]);

        min_dp[0] = arr[0] + prev_min[0].min(prev_min[1]);
        min_dp[1] = arr[1] + prev_min[0].min(prev_min[1]).min(prev_min[2]);
        min_dp[2] = arr[2] + prev_min[1].min(prev_min[2]);
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    let max_result = max_dp[0].max(max_dp[1]).max(max_dp[2]);
    let min_result = min_dp[0].min(min_dp[1]).min(min_dp[2]);
    writeln!(out, "{} {}", max_result, min_result).unwrap();
}
