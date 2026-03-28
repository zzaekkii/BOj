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
        self.tree[p] = 1;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn query(&self, st: usize, en: usize) -> usize {
        let mut left = self.size + st - 1;
        let mut right = self.size + en - 1;
        let mut res = 0usize;

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
    let mut player = Vec::<(usize, usize)>::with_capacity(n);
    for i in 0..n {
        let skill: usize = iter.next().unwrap().parse().unwrap();
        player.push((skill, i));
    }

    player.sort_unstable_by(|a, b| a.0.cmp(&b.0));

    for i in 0..n {
        player[i].0 = i + 1;
    }

    player.sort_unstable_by(|a, b| a.1.cmp(&b.1));

    let mut seg = SegTree::new(n);
    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 0..n {
        writeln!(out, "{}", seg.query(player[i].0 + 1, n) + 1).unwrap();
        seg.update(player[i].0);
    }
}
