use std::io::{self, Read, Write};

struct SegTree {
    size: usize,
    tree: Vec<i64>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        SegTree {
            size,
            tree: vec![0i64; size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, val: i64) {
        let mut p = self.size + idx - 1;
        self.tree[p] = val;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn query(&self, st: usize, en: usize) -> i64 {
        let mut left = self.size + st - 1;
        let mut right = self.size + en - 1;
        let mut res = 0i64;

        while left <= right {
            if left & 1 == 1 {
                res += self.tree[left];
                left += 1;
            }

            if right & 1 == 0 {
                res += self.tree[right];
                right -= 1;
            }

            left >>= 1;
            right >>= 1;
        }

        res
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
        let num: i64 = iter.next().unwrap().parse().unwrap();
        seg.update(i, num);
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..q {
        let mut x: usize = iter.next().unwrap().parse().unwrap();
        let mut y: usize = iter.next().unwrap().parse().unwrap();
        let a: usize = iter.next().unwrap().parse().unwrap();
        let b: i64 = iter.next().unwrap().parse().unwrap();

        if x > y {
            std::mem::swap(&mut x, &mut y);
        }
        writeln!(out, "{}", seg.query(x, y)).unwrap();
        seg.update(a, b);
    }
}
