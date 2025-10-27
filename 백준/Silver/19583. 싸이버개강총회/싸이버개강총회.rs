use std::{collections::HashMap, io::{self, Read, Write}};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let (start_time, end_time, quit_time) = (
        time_to_u32(iter.next().unwrap()),
        time_to_u32(iter.next().unwrap()),
        time_to_u32(iter.next().unwrap()),
    );

    let mut name_to_index= HashMap::new();
    let mut attendance = vec![];
    let mut index = 0;

    while let Some(t_str) = iter.next() {
        let t = time_to_u32(t_str);
        let name = iter.next().unwrap();

        let num = *name_to_index.entry(name).or_insert_with(|| {
            attendance.push(0u8);
            let cur = index;
            index += 1;
            cur
        });

        if t <= start_time {
            attendance[num] |= 0b01;
        }
        if t >= end_time && t <= quit_time {
            attendance[num] |= 0b10;
        }
    }

    let result = attendance.iter().filter(|&&x| x == 0b11).count();

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", result).unwrap();
}

fn time_to_u32(time: &str) -> u32 {
    let bytes = time.as_bytes();
    let h = ((bytes[0] - b'0') as u32) * 10 + (bytes[1] - b'0') as u32;
    let m = ((bytes[3] - b'0') as u32) * 10 + (bytes[4] - b'0') as u32;

    h * 60 + m
}