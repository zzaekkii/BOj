use std::io::{self, Read, Write};

fn manacher(s: &str) -> usize {
    let mut t = Vec::with_capacity(s.len() * 2 + 1);

    t.push('#');
    for c in s.chars() {
        t.push(c);
        t.push('#');
    }

    let n = t.len();
    let mut p = vec![0usize; n];
    let (mut c, mut r) = (0usize, 0usize);

    for i in 0..n {
        if i < r {
            let sym = 2 * c - i;
            p[i] = p[sym].min(r - i);
        }

        while i + p[i] + 1 < n && i >= p[i] + 1 && t[i + p[i] + 1] == t[i - p[i] - 1] {
            p[i] += 1;
        }

        if i + p[i] > r {
            c = i;
            r = i + p[i];
        }
    }

    *p.iter().max().unwrap()
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let s = iter.next().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", manacher(s)).unwrap();
}
