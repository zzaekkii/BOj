use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = Vec::<usize>::with_capacity(n);
    for _ in 0..n {
        arr.push(iter.next().unwrap().parse().unwrap());
    }

    let k: usize = iter.next().unwrap().parse().unwrap();
    let max = k * arr[n - 1];
    let mut dp = vec![k + 1; max + 1];
    dp[0] = 0;

    for i in 1..=max {
        for &a in &arr {
            if i >= a {
                dp[i] = dp[i].min(dp[i - a] + 1);
            }
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 1..=max {
        if dp[i] > k {
            writeln!(
                out,
                "{} win at {}",
                if i % 2 == 0 { "holsoon" } else { "jjaksoon" },
                i
            )
            .unwrap();
            break;
        }
    }
}
