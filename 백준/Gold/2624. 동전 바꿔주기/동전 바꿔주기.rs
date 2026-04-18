use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut coin = Vec::<(usize, usize)>::with_capacity(k);
    for _ in 0..k {
        let amount: usize = iter.next().unwrap().parse().unwrap();
        let count: usize = iter.next().unwrap().parse().unwrap();
        coin.push((amount, count));
    }

    let mut dp = vec![0usize; t + 1];
    dp[0] = 1;

    for i in 0..k {
        for cur in (0..=t).rev() {
            for count in 1..=coin[i].1 {
                if cur < coin[i].0 * count {
                    continue;
                }
                dp[cur] += dp[cur - coin[i].0 * count];
            }
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", dp[t]).unwrap();
}
