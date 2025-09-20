use std::io::{self, Read, Write};

fn main() {
    let nums = inputs();

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    for n in nums {
        if is_square(n) && is_square(reverse(n)) {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
}

fn inputs() -> Vec<u64> {
    let mut inbuf = String::new();
    io::stdin().read_to_string(&mut inbuf).unwrap();

    let mut lines = inbuf.lines();

    let t: usize = lines.next().unwrap().parse().unwrap();

    let nums: Vec<u64> = lines
        .take(t)
        .map(|line| line.trim().parse().unwrap())
        .collect();

    nums
}

fn reverse(mut x: u64) -> u64 {
    let mut res = 0;

    while x > 0 {
        res = res * 10 + x % 10;
        x /= 10;
    }

    res
}

fn is_square(x: u64) -> bool {
    let root = (x as f64).sqrt().floor() as u64;
    root * root == x
}