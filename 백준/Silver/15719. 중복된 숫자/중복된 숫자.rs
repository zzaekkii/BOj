use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut num = vec![false; n + 1];

    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..n {
        let x: usize = iter.next().unwrap().parse().unwrap();
        if num[x] {
            writeln!(out, "{}", x).unwrap();
            return;
        }
        num[x] = true;
    }
}
