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
        let val = self.lazy[node];

        if val == 0 {
            return;
        }

        self.tree[node] += val * (end as i64 - start as i64 + 1);

        if start != end {
            self.lazy[node * 2] += val;
            self.lazy[node * 2 + 1] += val;
        }

        self.lazy[node] = 0;
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
    fn update_range(
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
        self.update_range(node * 2, start, mid, left, right, val);
        self.update_range(node * 2 + 1, mid + 1, end, left, right, val);

        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1];
    }

    #[inline]
    fn query(&mut self, node: usize, start: usize, end: usize, left: usize, right: usize) -> i64 {
        self.propagate(node, start, end);

        if right < start || end < left {
            return 0i64;
        }

        if left <= start && end <= right {
            return self.tree[node];
        }

        let mid = (start + end) / 2;
        let left_res = self.query(node * 2, start, mid, left, right);
        let right_res = self.query(node * 2 + 1, mid + 1, end, left, right);

        left_res + right_res
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
    let k: usize = iter.next().unwrap().parse().unwrap();

    let mut seg = SegTree::new(n);
    for i in 1..=n {
        let num: i64 = iter.next().unwrap().parse().unwrap();
        seg.update(i, num);
    }

    let cnt = m + k;
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..cnt {
        let q: usize = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                let left: usize = iter.next().unwrap().parse().unwrap();
                let right: usize = iter.next().unwrap().parse().unwrap();
                let val: i64 = iter.next().unwrap().parse().unwrap();
                seg.update_range(ROOT, ROOT, seg.size, left, right, val);
            }
            2 => {
                let left: usize = iter.next().unwrap().parse().unwrap();
                let right: usize = iter.next().unwrap().parse().unwrap();
                writeln!(out, "{}", seg.query(ROOT, ROOT, seg.size, left, right)).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
