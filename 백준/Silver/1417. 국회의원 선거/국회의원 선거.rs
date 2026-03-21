use std::{
    collections::BinaryHeap,
    io::{self, Read, Write},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut voted = BinaryHeap::<usize>::with_capacity(n);

    let mut dasom: usize = iter.next().unwrap().parse().unwrap();
    for _ in 2..=n {
        let amount: usize = iter.next().unwrap().parse().unwrap();
        voted.push(amount);
    }

    let mut ans = 0usize;
    while let Some(&cur) = voted.peek() {
        if dasom > cur {
            break;
        }

        let mut cur = voted.pop().unwrap();
        cur -= 1;
        dasom += 1;
        
        voted.push(cur);
        ans += 1;
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", ans).unwrap();
}
