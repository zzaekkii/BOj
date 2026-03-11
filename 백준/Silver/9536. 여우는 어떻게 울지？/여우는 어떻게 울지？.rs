use std::{
    collections::HashSet,
    io::{self, BufRead, Write},
};

const QUESTION: &str = "what does the fox say?";

fn main() {
    let mut lines = io::stdin().lock().lines();

    let t: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for _ in 0..t {
        let sounds: Vec<String> = lines
            .next()
            .unwrap()
            .unwrap()
            .split_ascii_whitespace()
            .map(String::from)
            .collect();

        let mut others = HashSet::new();

        loop {
            let line = lines.next().unwrap().unwrap();

            if line == QUESTION {
                break;
            }

            others.insert(line.split_ascii_whitespace().nth(2).unwrap().to_string());
        }

        for s in sounds {
            if !others.contains(&s) {
                write!(out, "{} ", s).unwrap();
            }
        }
        writeln!(out).unwrap();
    }
}
