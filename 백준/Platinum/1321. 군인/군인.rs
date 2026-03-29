use std::io::{self, Read, Write};

struct SegTree {
    size: usize,
    tree: Vec<i32>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self {
            size,
            tree: vec![0i32; size * 2],
        }
    }

    #[inline]
    fn update(&mut self, idx: usize, diff: i32) {
        let mut p = self.size + idx - 1;
        self.tree[p] += diff;

        while p > 1 {
            p >>= 1;
            self.tree[p] = self.tree[p * 2] + self.tree[p * 2 + 1];
        }
    }

    #[inline]
    fn find_kth(&self, mut k: i32) -> usize {
        let mut node = 1;

        while node < self.size {
            node <<= 1;

            if self.tree[node] < k {
                k -= self.tree[node];
                node += 1;
            }
        }

        node - self.size + 1
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut seg = SegTree::new(n);

    for i in 1..=n {
        let x: i32 = iter.next().unwrap().parse().unwrap();
        seg.update(i, x);
    }

    let m: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..m {
        let q: i32 = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                let i: usize = iter.next().unwrap().parse().unwrap();
                let a: i32 = iter.next().unwrap().parse().unwrap();
                seg.update(i, a);
            }
            2 => {
                let k: i32 = iter.next().unwrap().parse().unwrap();
                writeln!(out, "{}", seg.find_kth(k)).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
