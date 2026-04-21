use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let monkey: usize = iter.next().unwrap().parse().unwrap();
    let puppy: usize = iter.next().unwrap().parse().unwrap();

    let difference = puppy - monkey;

    let mut out = io::BufWriter::new(io::stdout().lock());
    if difference == 0 {
        writeln!(out, "0").unwrap();
        return;
    }

    let mut n = 1usize;
    while n * n < difference {
        n += 1;
    }

    let ans = if n * n - n < difference {
        n * 2 - 1
    } else {
        n * 2 - 2
    };

    writeln!(out, "{}", ans).unwrap();
}
