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
    let p: usize = iter.next().unwrap().parse().unwrap();

    let mut step = vec![0usize; p];

    for i in 0..p {
        step[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut queues = vec![VecDeque::<(usize, usize)>::new(); p];
    let mut board = Vec::<Vec<u8>>::with_capacity(n);
    let mut area = vec![0usize; p];

    for y in 0..n {
        let row = iter.next().unwrap().as_bytes().to_vec();

        for x in 0..m {
            if (b'1'..=b'9').contains(&row[x]) {
                let player = (row[x] - b'1') as usize;

                queues[player].push_back((y, x));
                area[player] += 1;
            }
        }

        board.push(row);
    }

    let directions = [(-1, 0), (0, 1), (1, 0), (0, -1)];

    loop {
        let mut flag = false;

        for player in 0..p {
            for _ in 0..step[player] {
                let size = queues[player].len();

                if size == 0 {
                    break;
                }

                for _ in 0..size {
                    let (y, x) = queues[player].pop_front().unwrap();

                    for (dy, dx) in directions {
                        let ny = y as isize + dy;
                        let nx = x as isize + dx;

                        if ny < 0 || ny >= n as isize || nx < 0 || nx >= m as isize {
                            continue;
                        }

                        let ny = ny as usize;
                        let nx = nx as usize;

                        if board[ny][nx] != b'.' {
                            continue;
                        }

                        board[ny][nx] = b'1' + player as u8;
                        area[player] += 1;
                        flag = true;
                        
                        queues[player].push_back((ny, nx));
                    }
                }
            }
        }

        if !flag {
            break;
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 0..p {
        write!(out, "{} ", area[i]).unwrap();
    }
}
