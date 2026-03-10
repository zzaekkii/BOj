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
    fn update(&mut self, idx: usize) {
        let mut p = self.size + idx - 1;
        self.tree[p] += 1;

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

    let test_case: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for t in 1..=test_case {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let m: usize = iter.next().unwrap().parse().unwrap();
        let k: usize = iter.next().unwrap().parse().unwrap();

        let mut roads = Vec::<(usize, usize)>::with_capacity(k);
        for _ in 0..k {
            let a: usize = iter.next().unwrap().parse().unwrap();
            let b: usize = iter.next().unwrap().parse().unwrap();
            roads.push((a, b));
        }

        roads.sort_unstable();

        let mut seg = SegTree::new(m);
        let mut ans = 0i64;

        for (_, b) in roads {
            ans += seg.query(b + 1, m);
            seg.update(b);
        }

        writeln!(out, "Test case {}: {}", t, ans).unwrap();
    }
}
