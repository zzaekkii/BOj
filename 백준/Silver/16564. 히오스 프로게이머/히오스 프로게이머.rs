use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let k: u64 = iter.next().unwrap().parse().unwrap();

    let mut level = vec![0u64; n];
    let mut min_level = u64::MAX;

    for i in 0..n {
        level[i] = iter.next().unwrap().parse().unwrap();
        min_level = min_level.min(level[i]);
    }

    let mut left = min_level;
    let mut right = min_level + k;
    let mut answer = min_level;

    while left <= right {
        let mid = (left + right) / 2;

        let mut need = 0u64;
        for &l in &level {
            if mid <= l {
                continue;
            }
            need += mid - l;
            if need > k {
                break;
            }
        }

        if need <= k {
            answer = mid;
            left = mid + 1;
            continue;
        }

        right = mid - 1;
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer).unwrap();
}
