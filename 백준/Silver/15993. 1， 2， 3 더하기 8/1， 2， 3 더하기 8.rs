use std::io::{self, Read, Write};

const MOD: usize = 1_000_000_009;
const MAX: usize = 100_000;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let mut odd = vec![0usize; MAX + 1];
    let mut even = vec![0usize; MAX + 1];

    odd[1] = 1;
    odd[2] = 1;
    odd[3] = 2;

    even[1] = 0;
    even[2] = 1;
    even[3] = 2;

    for i in 4..=MAX {
        odd[i] = (even[i - 1] + even[i - 2] + even[i - 3]) % MOD;
        even[i] = (odd[i - 1] + odd[i - 2] + odd[i - 3]) % MOD;
    }

    let t: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        writeln!(out, "{} {}", odd[n], even[n]).unwrap();
    }
}
