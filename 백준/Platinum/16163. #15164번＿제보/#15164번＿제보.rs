use std::io::{self, Read, Write};

fn manacher(s: &str) -> usize {
    let bytes = s.as_bytes();
    let mut t = Vec::with_capacity(bytes.len() * 2 + 1);

    t.push(b'#');
    for &c in bytes {
        t.push(c);
        t.push(b'#');
    }

    let n = t.len();
    let mut p = vec![0usize; n + 1];
    let (mut c, mut r) = (0usize, 0usize);
    let mut res = 0usize;

    for i in 0..n {
        if i < r {
            p[i] = p[c * 2 - i].min(r - i);
        }

        while i + p[i] + 1 < n && i >= p[i] + 1 && t[i + p[i] + 1] == t[i - p[i] - 1] {
            p[i] += 1;
        }

        if i + p[i] > r {
            c = i;
            r = i + p[i];
        }

        res += (p[i] + 1) / 2;
    }

    res
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let s = iter.next().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", manacher(s)).unwrap();
}
