use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    
    let mut r: u64 = iter.next().unwrap().parse().unwrap();
    let k: u64 = iter.next().unwrap().parse().unwrap();
    let m: u64 = iter.next().unwrap().parse().unwrap();
    
    let mut res: u64 = m / k;
    
    if res >= 64 {
        r = 0;
    } else {
        r >>= res;
    }
    
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", r).unwrap();
}
