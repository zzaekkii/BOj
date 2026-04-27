use std::io::{self, Read, Write};

const MAX_TEMPERATURE: usize = 65_536;

struct SegTree {
    size: usize,
    tree: Vec<usize>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self {
            size,
            tree: vec![0usize; size * 2],
        }
    }

    #[inline]
    fn add(&mut self, idx: usize) {
        let mut p = self.size + idx;
        self.tree[p] += 1;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn remove(&mut self, idx: usize) {
        let mut p = self.size + idx;
        self.tree[p] -= 1;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn query(&self, mut order: usize) -> usize {
        let mut node = 1;

        while node < self.size {
            let left = node * 2;

            if self.tree[left] >= order {
                node = left;
                continue;
            }

            order -= self.tree[left];
            node = left + 1;
        }

        node - self.size
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut temperatures = vec![0usize; n];
    for i in 0..n {
        temperatures[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut seg = SegTree::new(MAX_TEMPERATURE + 1);
    let median_order = (k + 1) / 2;
    let mut answer = 0u64;

    for i in 0..n {
        seg.add(temperatures[i]);

        if i + 1 >= k {
            answer += seg.query(median_order) as u64;
            seg.remove(temperatures[i + 1 - k]);
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer).unwrap();
}
