use std::{
    io::{self, Read, Write},
    vec,
};

fn manacher(arr: &[usize]) -> Vec<usize> {
    let mut t = Vec::with_capacity(arr.len() * 2 + 1);

    t.push(0);
    for &n in arr {
        t.push(n);
        t.push(0);
    }

    let n = t.len();
    let mut p = vec![0usize; n + 1];
    let (mut c, mut r) = (0usize, 0usize);

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
    }

    p
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = vec![0usize; n];
    for i in 0..n {
        arr[i] = iter.next().unwrap().parse().unwrap();
    }

    let p = manacher(&arr);
    let m: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..m {
        let s: usize = iter.next().unwrap().parse::<usize>().unwrap() - 1;
        let e: usize = iter.next().unwrap().parse::<usize>().unwrap() - 1;

        let mid = s + e + 1;
        let len = e - s + 1;
        writeln!(out, "{}", if p[mid] >= len { 1 } else { 0 }).unwrap();
    }
}
