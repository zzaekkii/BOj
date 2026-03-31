use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut guitars = vec![0u64; n];
    for i in 0..n {
        let _name = iter.next().unwrap();
        let s = iter.next().unwrap();

        let mut mask = 0u64;
        for (j, c) in s.chars().enumerate() {
            if c == 'Y' {
                mask |= 1 << j;
            }
        }
        guitars[i] = mask;
    }

    let mut max_songs = 0;
    let mut min_guitars = usize::MAX;
    for subset in 1..(1 << n) {
        let mut mask = 0u64;
        let mut count = 0usize;

        for i in 0..n {
            if (subset & (1 << i)) != 0 {
                mask |= guitars[i];
                count += 1;
            }
        }

        let songs = mask.count_ones() as usize;

        if songs > max_songs {
            max_songs = songs;
            min_guitars = count;
        } else if songs == max_songs {
            min_guitars = min_guitars.min(count);
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(
        out,
        "{}",
        if max_songs == 0 {
            -1
        } else {
            min_guitars as i32
        }
    )
    .unwrap();
}
