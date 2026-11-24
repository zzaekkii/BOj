use std::io::{self, Read, Write};
use std::cmp::Ordering::*;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..3 {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let mut sum = 0i128;

        for _ in 0..n {
            let num: i128 = iter.next().unwrap().parse().unwrap();
            sum += num;
        }

        let answer = match sum.cmp(&0) {
            Greater => "+",
            Less => "-",
            Equal => "0",
        };

        writeln!(out, "{}", answer).unwrap();
    }
}
