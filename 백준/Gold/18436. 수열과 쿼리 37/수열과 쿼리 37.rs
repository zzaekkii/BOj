use std::{
    io::{self, Read, Write},
    vec,
};

struct SegTree {
    size: usize,
    tree: Vec<(usize, usize)>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        SegTree {
            size,
            tree: vec![(0usize, 0usize); size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, val: usize) {
        let mut p = self.size + idx - 1;
        if val % 2 == 0 {
            self.tree[p] = (1, 0);
        } else {
            self.tree[p] = (0, 1);
        }

        while p > 1 {
            p >>= 1;
            self.tree[p].0 = self.tree[p * 2].0 + self.tree[p * 2 + 1].0;
            self.tree[p].1 = self.tree[p * 2].1 + self.tree[p * 2 + 1].1;
        }
    }

    #[inline]
    fn query(&self, st: usize, en: usize, is_even: bool) -> usize {
        let mut left = self.size + st - 1;
        let mut right = self.size + en - 1;
        let mut res = (0usize, 0usize);

        while left <= right {
            if left & 1 == 1 {
                res.0 += self.tree[left].0;
                res.1 += self.tree[left].1;
                left += 1;
            }

            if right & 1 == 0 {
                res.0 += self.tree[right].0;
                res.1 += self.tree[right].1;
                right -= 1;
            }

            left >>= 1;
            right >>= 1;
        }

        if is_even {
            res.0
        } else {
            res.1
        }
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
        let i: usize = iter.next().unwrap().parse().unwrap();
        let x: usize = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                seg.update(i, x);
            }
            2 => {
                writeln!(out, "{}", seg.query(i, x, true)).unwrap();
            }
            3 => {
                writeln!(out, "{}", seg.query(i, x, false)).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
