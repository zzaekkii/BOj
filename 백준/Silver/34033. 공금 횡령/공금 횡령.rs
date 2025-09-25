use std::{collections::HashMap, io::{self, Read, Write}};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut map = HashMap::new();
    for _ in 0..n {
        let name: String = iter.next().unwrap().to_string();
        let cost: usize = iter.next().unwrap().parse().unwrap();
        map.insert(name, cost);
    }

    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    let mut count: usize = 0;

    for _ in 0..m {
        let name: String = iter.next().unwrap().to_string();
        let cost: usize = iter.next().unwrap().parse().unwrap();

        if map.get(&name).unwrap() * 105 < cost * 100 {
            count +=1;
        }
    }

    writeln!(out, "{}", count).unwrap();
}