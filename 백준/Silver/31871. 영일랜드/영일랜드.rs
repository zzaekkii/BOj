use std::io::{self, Read, Write};

fn dfs(
    cur: usize,
    visited: &mut [bool],
    count: usize,
    cost: i32,
    n: usize,
    dist: &[Vec<i32>],
    answer: &mut i32,
) {
    if count == n {
        if dist[cur][0] != -1 {
            *answer = (*answer).max(cost + dist[cur][0]);
        }
        return;
    }

    for i in 1..=n {
        if !visited[i] && dist[cur][i] != -1 {
            visited[i] = true;
            dfs(i, visited, count + 1, cost + dist[cur][i], n, dist, answer);
            visited[i] = false;
        }
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut dist = vec![vec![-1i32; n + 1]; n + 1];

    for _ in 0..m {
        let u: usize = iter.next().unwrap().parse().unwrap();
        let v: usize = iter.next().unwrap().parse().unwrap();
        let d: i32 = iter.next().unwrap().parse().unwrap();

        dist[u][v] = dist[u][v].max(d);
    }

    let mut answer = -1i32;
    let mut visited = vec![false; n + 1];
    for i in 1..=n {
        if dist[0][i] != -1 {
            visited[i] = true;
            dfs(i, &mut visited, 1, dist[0][i], n, &dist, &mut answer);
            visited[i] = false;
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer);
}
