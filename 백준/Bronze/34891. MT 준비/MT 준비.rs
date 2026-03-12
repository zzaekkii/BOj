use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();
    
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", (n + m - 1) / m).unwrap();
}
