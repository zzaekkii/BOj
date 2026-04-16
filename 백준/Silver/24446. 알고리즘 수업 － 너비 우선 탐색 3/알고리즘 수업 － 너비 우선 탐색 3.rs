use std::io::{self, Read, Write};
use std::collections::VecDeque;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    let r: usize = iter.next().unwrap().parse().unwrap();

    let mut graph = vec![Vec::<usize>::new(); n + 1];

    for _ in 0..m {
        let u: usize = iter.next().unwrap().parse().unwrap();
        let v: usize = iter.next().unwrap().parse().unwrap();
        graph[u].push(v);
        graph[v].push(u);
    }

    let mut depth = vec![-1i32; n + 1];
    let mut q = VecDeque::<usize>::new();

    depth[r] = 0;
    q.push_back(r);

    while let Some(cur) = q.pop_front() {
        for &next in &graph[cur] {
            if depth[next] == -1 {
                depth[next] = depth[cur] + 1;
                q.push_back(next);
            }
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 1..=n {
        writeln!(out, "{}", depth[i]).unwrap();
    }
}
