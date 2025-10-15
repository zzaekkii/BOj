use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    
    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = vec![0; n];
    for i in 0..n {
        arr[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut ans: usize = 1;
    let mut inc: usize = 1;
    let mut dec: usize = 1;
    for i in 1..n {
        if arr[i] > arr[i-1] {
            inc += 1;
            dec = 1;
            ans = ans.max(inc);
        } else if arr[i] < arr[i-1] {
            dec += 1;
            inc = 1;
            ans = ans.max(dec);
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", ans).unwrap();
}