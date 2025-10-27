use std::{collections::HashMap, io::{self, BufRead, Write}};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines().flatten();

    let times: Vec<String> = lines.next().unwrap()
                                .split_whitespace()
                                .map(|s| s.to_string()).collect();
    
    let (start_time, end_time, quit_time) = (
        time_to_u32(&times[0]),
        time_to_u32(&times[1]),
        time_to_u32(&times[2]),
    );

    let mut name_to_index: HashMap<String, usize> = std::collections::HashMap::new();
    let mut attendance: Vec<[bool; 2]> = vec![];
    let mut index = 0;

    for line in lines {
        let mut iter = line.split_whitespace();
        let t = time_to_u32(iter.next().unwrap());
        let name = iter.next().unwrap();

        let num = *name_to_index.entry(name.to_string()).or_insert_with(|| {
            attendance.push([false; 2]);
            let cur_index = index;
            index += 1;
            cur_index
        });

        if t <= start_time {
            attendance[num][0] = true;
        }

        if t >= end_time && t <= quit_time {
            attendance[num][1] = true;
        }
    }

    let result = attendance.iter().filter(|&att| att[0] && att[1]).count();

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", result).unwrap();
}

fn time_to_u32(time: &str) -> u32 {
    let hours: u32 = time[0..2].parse().unwrap();
    let minutes: u32 = time[3..5].parse().unwrap();

    hours * 60 + minutes
}