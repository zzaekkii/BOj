use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..t {
        let mut n: u64 = iter.next().unwrap().parse().unwrap();
        let mut m: u64 = iter.next().unwrap().parse().unwrap();

        while n > 0 {
            n >>= 1;
            m += 1;
        }

        writeln!(out, "{}", m).unwrap();
    }
}
