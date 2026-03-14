use std::io::{self, Read, Write};

const ROOT: usize = 1;

struct SegTree {
    size: usize,
    tree: Vec<i64>,
    lazy: Vec<i64>,
}

impl SegTree {
    fn new(n: usize) -> Self {
        let size = n.next_power_of_two();
        Self {
            size,
            tree: vec![0i64; size * 2],
            lazy: vec![0i64; size * 2],
        }
    }

    #[inline]
    fn propagate(&mut self, node: usize, start: usize, end: usize) {
        if self.lazy[node] != 0 {
            self.tree[node] += (end as i64 - start as i64 + 1) * self.lazy[node];

            if start != end {
                self.lazy[node * 2] += self.lazy[node];
                self.lazy[node * 2 + 1] += self.lazy[node];
            }

            self.lazy[node] = 0;
        }
    }

    #[inline]
    fn update(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        left: usize,
        right: usize,
        val: i64,
    ) {
        self.propagate(node, start, end);

        if right < start || end < left {
            return;
        }

        if left <= start && end <= right {
            self.lazy[node] += val;
            self.propagate(node, start, end);
            return;
        }

        let mid = (start + end) / 2;
        self.update(node * 2, start, mid, left, right, val);
        self.update(node * 2 + 1, mid + 1, end, left, right, val);

        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1];
    }

    #[inline]
    fn query(&mut self, node: usize, start: usize, end: usize, idx: usize) -> i64 {
        self.propagate(node, start, end);

        if start == end {
            return self.tree[node];
        }

        let mid = (start + end) / 2;

        if idx <= mid {
            self.query(node * 2, start, mid, idx)
        } else {
            self.query(node * 2 + 1, mid + 1, end, idx)
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
        let num: i64 = iter.next().unwrap().parse().unwrap();
        seg.update(ROOT, ROOT, n, i, i, num);
    }

    let m: usize = iter.next().unwrap().parse().unwrap();
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..m {
        let q: usize = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                let i: usize = iter.next().unwrap().parse().unwrap();
                let j: usize = iter.next().unwrap().parse().unwrap();
                let k: i64 = iter.next().unwrap().parse().unwrap();

                seg.update(ROOT, ROOT, n, i, j, k);
            }
            2 => {
                let x: usize = iter.next().unwrap().parse().unwrap();
                writeln!(out, "{}", seg.query(ROOT, ROOT, n, x)).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
