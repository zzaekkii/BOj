use std::{
    collections::VecDeque,
    io::{self, Read, Write},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut board = vec![vec![b'0'; m]; n];
    let mut start = (0usize, 0usize);
    for i in 0..n {
        let line = iter.next().unwrap().as_bytes();
        for j in 0..m {
            board[i][j] = line[j];

            if line[j] == b'2' {
                start = (i, j);
            }
        }
    }

    let mut visited = vec![vec![false; m]; n];
    let mut q = VecDeque::<(usize, usize, usize)>::new();
    q.push_back((start.0, start.1, 0usize));
    visited[start.0][start.1] = true;

    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];

    let mut out = io::BufWriter::new(io::stdout().lock());
    while let Some((x, y, dist)) = q.pop_front() {
        let cur = board[x][y];

        if cur == b'3' || cur == b'4' || cur == b'5' {
            writeln!(out, "TAK").unwrap();
            writeln!(out, "{}", dist).unwrap();
            return;
        }

        for dir in 0..4 {
            let nx = x as i32 + dx[dir];
            let ny = y as i32 + dy[dir];

            if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 {
                continue;
            }

            let nx = nx as usize;
            let ny = ny as usize;

            if visited[nx][ny] {
                continue;
            }

            if board[nx][ny] == b'1' {
                continue;
            }

            visited[nx][ny] = true;
            q.push_back((nx, ny, dist + 1));
        }
    }

    writeln!(out, "NIE").unwrap();
}
