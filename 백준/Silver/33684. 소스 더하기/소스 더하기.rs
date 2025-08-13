use std::io::{self, Read, Write};

fn main() {
    let (n, k, mut source) = inputs();

    source.sort_unstable();

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let ans: i64 = if source[n-1] > k {
        0
    } else if source[0] <= 0 {
        -1
    } else {
        let mut sum: i64 = 0;

        for i in 1..n {
            sum += (k - source[i]) / source[0];
        }

        sum + 1
    };

    writeln!(out, "{}", ans).unwrap();
}

fn inputs() -> (usize, i64, Vec<i64>) {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let k: i64 = it.next().unwrap().parse().unwrap();

    let mut source = vec![0i64; n];
    for i in 0..n {
        source[i] = it.next().unwrap().parse().unwrap();
    }

    (n, k, source)
}