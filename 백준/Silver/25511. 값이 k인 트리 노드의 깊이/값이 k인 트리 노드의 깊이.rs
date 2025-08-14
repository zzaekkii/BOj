use std::io::{self, Read, Write};

fn main() {
    let (mut target, parent) = inputs();

    let mut cnt: usize = 0;
    while target != 0 {
        target = parent[target];
        cnt += 1;
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", cnt).unwrap();
}

fn inputs() -> (usize, Vec<usize>) {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().map(|x| x.parse::<usize>().unwrap());

    let n = it.next().unwrap();
    let k= it.next().unwrap();

    let mut parent = vec![0usize; n+1];
    for _ in 0..(n-1) {
        let p = it.next().unwrap();
        let c = it.next().unwrap() as usize;

        parent[c] = p;
    }

    let mut target: usize = 0;
    for i in 0..n {
        let t = it.next().unwrap();

        if t == k {
            target = i;
        }
    }

    (target, parent)
}