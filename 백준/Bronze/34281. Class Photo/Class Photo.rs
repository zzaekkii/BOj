use std::io::{self, Read, Write};

fn main() {
    let (n, m) = inputs();

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    writeln!(out, "{}", n * m);
}

fn inputs() -> (usize, usize){
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    (n, m)
}