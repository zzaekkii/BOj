use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let mut arr = Vec::<usize>::with_capacity(n);

        for _ in 0..n {
            arr.push(iter.next().unwrap().parse().unwrap());
        }

        arr.sort_unstable();

        let mut ans = 0usize;
        for i in 0..n - 2 {
            ans = ans.max(arr[i + 2] - arr[i]);
        }

        writeln!(out, "{}", ans).unwrap();
    }
}
