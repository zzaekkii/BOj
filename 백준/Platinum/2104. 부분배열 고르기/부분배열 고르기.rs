use std::io::{self, Read, Write};

struct SegTree {
    size: usize,
    tree: Vec<(u64, usize)>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self {
            size,
            tree: vec![(0u64, 0usize); size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, val: u64) {
        let mut p = self.size + idx - 1;
        self.tree[p] = (val, idx);

        while p > 1 {
            p >>= 1;

            let left = p * 2;
            let right = p * 2 + 1;

            self.tree[p].0 = self.tree[left].0 + self.tree[right].0;
            self.tree[p].1 = self.better_idx(self.tree[left].1, self.tree[right].1);
        }
    }

    #[inline]
    fn value_at(&self, idx: usize) -> u64 {
        if idx == 0 {
            u64::MAX
        } else {
            self.tree[self.size + idx - 1].0
        }
    }

    #[inline]
    fn better_idx(&self, a: usize, b: usize) -> usize {
        if a == 0 {
            return b;
        }
        if b == 0 {
            return a;
        }

        if self.value_at(a) <= self.value_at(b) {
            a
        } else {
            b
        }
    }

    #[inline]
    fn query(&self, st: usize, en: usize) -> (u64, usize) {
        let mut left = self.size + st - 1;
        let mut right = self.size + en - 1;
        let mut result = (0u64, 0usize);

        while left <= right {
            if left & 1 == 1 {
                result = self.merge(result, self.tree[left]);
                left += 1;
            }

            if right & 1 == 0 {
                result = self.merge(result, self.tree[right]);
                right -= 1;
            }

            left >>= 1;
            right >>= 1;
        }

        result
    }

    #[inline]
    fn merge(&self, a: (u64, usize), b: (u64, usize)) -> (u64, usize) {
        (a.0 + b.0, self.better_idx(a.1, b.1))
    }
}

fn calculate_max_score(seg: &SegTree, n: usize) -> u64 {
    let mut answer = 0u64;
    let mut stack = vec![(1usize, n)];

    while let Some((st, en)) = stack.pop() {
        if st > en {
            continue;
        }

        let (sum, min_idx) = seg.query(st, en);
        let min_value = seg.value_at(min_idx);

        answer = answer.max(sum * min_value);

        if st < min_idx {
            stack.push((st, min_idx - 1));
        }

        if min_idx < en {
            stack.push((min_idx + 1, en));
        }
    }

    answer
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut seg = SegTree::new(n);

    for i in 1..=n {
        let val: u64 = iter.next().unwrap().parse().unwrap();
        seg.update(i, val);
    }

    let answer = calculate_max_score(&seg, n);
    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", answer).unwrap();
}
