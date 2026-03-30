use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let song_count: usize = iter.next().unwrap().parse().unwrap();
    let song_duration: usize = iter.next().unwrap().parse().unwrap();
    let ring_interval: usize = iter.next().unwrap().parse().unwrap();

    let mut ring_sequence = 0usize;

    let mut out = io::BufWriter::new(io::stdout().lock());
    loop {
        let current_time = ring_sequence * ring_interval;

        let song_sequence = current_time / (song_duration + 5);
        let song_start = song_sequence * (song_duration + 5);
        let song_end = song_start + song_duration;

        if song_sequence >= song_count || current_time < song_start || song_end <= current_time {
            writeln!(out, "{}", current_time).unwrap();
            return;
        }

        ring_sequence += 1;
    }
}
