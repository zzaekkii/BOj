use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut arr = vec![0usize; n];
    for i in 0..n {
        arr[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut left = 0usize;
    let mut odd = 0usize;
    let mut answer = 0usize;
    for right in 0..n {
        if arr[right] % 2 != 0 {
            odd += 1;
        }

        while odd > k {
            if arr[left] % 2 != 0 {
                odd -= 1;
            }
            left += 1;
        }

        answer = answer.max(right - left + 1 - odd);
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer).unwrap();
}
