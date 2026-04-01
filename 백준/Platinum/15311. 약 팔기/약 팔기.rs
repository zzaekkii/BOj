use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    
    writeln!(out, "2000").unwrap();
    for _ in 0..1000 {
        write!(out, "1 ").unwrap();
    }
    for _ in 0..1000 {
        write!(out, "1000 ").unwrap();
    }
}
