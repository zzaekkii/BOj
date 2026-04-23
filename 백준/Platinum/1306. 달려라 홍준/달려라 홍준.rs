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

    let mut signs = vec![0usize; n + 1];
    for i in 1..=n {
        let sign: usize = iter.next().unwrap().parse().unwrap();
        signs[i] = sign;
    }

    let sight = m * 2 - 1;

    let mut brights = VecDeque::<usize>::new();
    let mut out = io::BufWriter::new(io::stdout().lock());

    for i in 1..=n {
        while !brights.is_empty() && signs[*brights.back().unwrap()] <= signs[i] {
            brights.pop_back();
        }

        brights.push_back(i);

        while !brights.is_empty() && *brights.front().unwrap() < i.saturating_sub(sight) + 1 {
            brights.pop_front();
        }

        if i >= sight {
            write!(out, "{} ", signs[*brights.front().unwrap()]).unwrap();
        }
    }
}
