use std::io::{self, Read, Write};

fn main() {
    let miles = inputs();
    
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    writeln!(out, "{}", miles * 2);
}

fn inputs() -> usize {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    
    let n: usize = it.next().unwrap().parse().unwrap();
    
    n
}