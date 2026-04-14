use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut machine = vec![0u64; n];

    for i in 0..n {
        machine[i] = iter.next().unwrap().parse().unwrap();
    }

    machine.sort_unstable();

    let mut ans = 0u64;
    let half = n / 2;

    if n % 2 == 0 {
        for i in 0..half {
            ans = ans.max(machine[i] + machine[n - 1 - i]);
        }
    } else {
        ans = machine[n - 1];
        for i in 0..half {
            ans = ans.max(machine[i] + machine[n - 1 - i - 1]);
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", ans).unwrap();
}
