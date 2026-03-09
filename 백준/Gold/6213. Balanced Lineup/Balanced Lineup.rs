use std::io::{self, Read, Write};

struct SegTree {
    size: usize,
    tree: Vec<(usize, usize)>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self { 
            size,
            tree: vec![(usize::MAX, usize::MIN); size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, val: usize) {
        let mut p = self.size + idx - 1;
        self.tree[p] = (val, val);

        while p > 1 {
            p >>= 1;
            self.tree[p].0 = self.tree[p * 2].0.min(self.tree[p * 2 + 1].0);
            self.tree[p].1 = self.tree[p * 2].1.max(self.tree[p * 2 + 1].1);
        }
    }

    #[inline]
    fn query(&self, l: usize, r: usize) -> usize {
        let mut left = self.size + l - 1;
        let mut right = self.size + r - 1;
        let mut res = (usize::MAX, usize::MIN);

        while left <= right {
            if left & 1 == 1 {
                res.0 = res.0.min(self.tree[left].0);
                res.1 = res.1.max(self.tree[left].1);
                left += 1;
            }

            if right & 1 == 0 {
                res.0 = res.0.min(self.tree[right].0);
                res.1 = res.1.max(self.tree[right].1);
                right -= 1;
            }

            left >>= 1;
            right >>= 1;
        }

        res.1 - res.0
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let q: usize = iter.next().unwrap().parse().unwrap();

    let mut seg = SegTree::new(n);
    for i in 1..=n {
        let num: usize = iter.next().unwrap().parse().unwrap();
        seg.update(i, num);
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..q {
        let a: usize = iter.next().unwrap().parse().unwrap();
        let b: usize = iter.next().unwrap().parse().unwrap();
        writeln!(out, "{}", seg.query(a, b)).unwrap();
    }
}
