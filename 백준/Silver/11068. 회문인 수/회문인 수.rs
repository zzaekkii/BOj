use std::io::{self, Read, Write};

fn is_palindrome(mut n: u32, base: u32) -> bool {
    let mut digits = Vec::new();

    while n > 0 {
        digits.push(n % base);
        n /= base;
    }

    let len = digits.len();
    for i in 0..len / 2 {
        if digits[i] != digits[len - 1 - i] {
            return false;
        }
    }

    true
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..t {
        let n: u32 = iter.next().unwrap().parse().unwrap();

        let mut found = 0;

        for base in 2..=64 {
            if is_palindrome(n, base) {
                found = 1;
                break;
            }
        }

        writeln!(out, "{}", found).unwrap();
    }
}
