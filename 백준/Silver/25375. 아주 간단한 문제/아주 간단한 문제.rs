use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let q: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..q {
        let a: u64 = iter.next().unwrap().parse().unwrap();
        let b: u64 = iter.next().unwrap().parse().unwrap();

        writeln!(out, "{}", if b % a == 0 && b / a >= 2 { 1 } else { 0 }).unwrap();
    }
}