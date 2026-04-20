use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();

    let mut graph = vec![Vec::<usize>::new(); n + 1];
    for _ in 0..(n - 1) {
        let a: usize = iter.next().unwrap().parse().unwrap();
        let b: usize = iter.next().unwrap().parse().unwrap();
        graph[a].push(b);
        graph[b].push(a);
    }

    let mut stack = Vec::with_capacity(n);
    stack.push((1usize, 0usize, 0usize)); // 현재 노드, 부모, 깊이
    let mut sum = 0usize;

    while let Some((cur, parent, depth)) = stack.pop() {
        let mut child_count = 0;

        for &next in &graph[cur] {
            if next == parent {
                continue;
            }
            child_count += 1;
            stack.push((next, cur, depth + 1));
        }

        if cur != 1 && child_count == 0 {
            sum += depth;
        }
    }

    let mut out = io::BufWriter::new(io::stdout());
    writeln!(out, "{}", if sum % 2 == 1 { "Yes" } else { "No" }).unwrap();
}
