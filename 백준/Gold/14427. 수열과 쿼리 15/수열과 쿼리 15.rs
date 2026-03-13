use std::{
    io::{self, Read, Write},
    usize,
};

struct SegTree {
    size: usize,
    tree: Vec<(usize, usize)>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self {
            size,
            tree: vec![(usize::MAX, usize::MAX); size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, val: usize) {
        let mut p = self.size + idx - 1;
        self.tree[p] = (val, idx);

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2].min(self.tree[p * 2 + 1]);
        }
    }

    #[inline]
    fn query(&self) -> usize {
        self.tree[1].1
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut seg = SegTree::new(n);
    for i in 1..=n {
        let num: usize = iter.next().unwrap().parse().unwrap();
        seg.update(i, num);
    }

    let m: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..m {
        let q: usize = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                let idx: usize = iter.next().unwrap().parse().unwrap();
                let v: usize = iter.next().unwrap().parse().unwrap();
                seg.update(idx, v);
            }
            2 => {
                writeln!(out, "{}", seg.query()).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
