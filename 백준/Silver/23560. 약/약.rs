use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();

    let mut sym = vec![0u64; 16];
    let mut asym = vec![0u64; 16];
    sym[1] = 2;
    asym[1] = 1;

    for i in 2..=n {
        sym[i] = 2 * sym[i - 1] + 2 * asym[i - 1];
        asym[i] = sym[i - 1] + asym[i - 1];
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", sym[n]).unwrap();
}
