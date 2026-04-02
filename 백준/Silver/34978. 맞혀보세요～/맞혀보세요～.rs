use std::{
    collections::HashMap,
    io::{self, Read, Write},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut rules = HashMap::<u8, Vec<u8>>::with_capacity(n);
    for _ in 0..n {
        let x = iter.next().unwrap().as_bytes()[0];
        let m: usize = iter.next().unwrap().parse().unwrap();

        for _ in 0..m {
            let y = iter.next().unwrap().as_bytes()[0];

            rules.entry(x).or_insert(Vec::with_capacity(m)).push(y);
        }
    }

    let s = iter.next().unwrap().as_bytes();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for w in s.windows(2) {
        let cur = w[0];
        let next = w[1];

        if let Some(rule) = rules.get(&cur) {
            if !rule.contains(&next) {
                writeln!(out, "no").unwrap();
                return;
            }
        }
    }

    writeln!(out, "yes").unwrap();
}
