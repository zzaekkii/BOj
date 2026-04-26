use std::io::{self, Read, Write};

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
    fn update(&mut self, idx: usize) {
        let mut p = self.size + idx - 1;
        self.tree[p] += 1;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn query(&self, target: usize) -> usize {
        let mut left = self.size + target;
        let mut right = self.size + self.size - 1;
        let mut result = 0usize;

        while left <= right {
            if left & 1 == 1 {
                result += self.tree[left];
                left += 1;
            }

            if right & 1 == 0 {
                result += self.tree[right];
                right -= 1;
            }

            left >>= 1;
            right >>= 1;
        }

        result
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut seg = SegTree::new(n);
    let mut answer = 0u64;

    for _ in 0..n {
        let x: usize = iter.next().unwrap().parse().unwrap();
        answer += seg.query(x) as u64;
        seg.update(x);
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer).unwrap();
}
