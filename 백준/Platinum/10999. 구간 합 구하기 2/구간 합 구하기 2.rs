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
    fn propagate(&mut self, node: usize, len: i64) {
        let val = self.lazy[node];

        if val == 0 {
            return;
        }

        self.tree[node] += val * len;

        if node < self.size {
            self.lazy[node * 2] += val;
            self.lazy[node * 2 + 1] += val;
        }

        self.lazy[node] = 0;
    }

    fn build(&mut self, node: usize, start: usize, end: usize, arr: &[i64]) {
        if start == end {
            if start < arr.len() {
                self.tree[node] = arr[start];
            }
            return;
        }

        let mid = start + (end - start) / 2;
        self.build(node * 2, start, mid, arr);
        self.build(node * 2 + 1, mid + 1, end, arr);

        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1];
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
        self.propagate(node, (end - start + 1) as i64);

        if right < start || end < left {
            return;
        }

        if left <= start && end <= right {
            self.lazy[node] += val;
            self.propagate(node, (end - start + 1) as i64);
            return;
        }

        let mid = start + (end - start) / 2;
        self.update_range(node * 2, start, mid, left, right, val);
        self.update_range(node * 2 + 1, mid + 1, end, left, right, val);

        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1];
    }

    #[inline]
    fn query(&mut self, node: usize, start: usize, end: usize, left: usize, right: usize) -> i64 {
        self.propagate(node, (end - start + 1) as i64);

        if right < start || end < left {
            return 0i64;
        }

        if left <= start && end <= right {
            return self.tree[node];
        }

        let mid = start + (end - start) / 2;
        let left_res = self.query(node * 2, start, mid, left, right);
        let right_res = self.query(node * 2 + 1, mid + 1, end, left, right);

        left_res + right_res
    }

    #[inline]
    fn build_from(&mut self, arr: &[i64]) {
        self.build(ROOT, ROOT, self.size, arr);
    }

    #[inline]
    fn range_add(&mut self, l: usize, r: usize, val: i64) {
        self.update_range(ROOT, ROOT, self.size, l, r, val);
    }

    #[inline]
    fn range_sum(&mut self, l: usize, r: usize) -> i64 {
        self.query(ROOT, ROOT, self.size, l, r)
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
    let mut arr = vec![0i64; n + 1];
    for i in 1..=n {
        let num: i64 = iter.next().unwrap().parse().unwrap();
        arr[i] = num;
    }
    seg.build_from(&arr);

    let cnt = m + k;
    let mut out = io::BufWriter::new(io::stdout().lock());
    for _ in 0..cnt {
        let q: usize = iter.next().unwrap().parse().unwrap();

        match q {
            1 => {
                let left: usize = iter.next().unwrap().parse().unwrap();
                let right: usize = iter.next().unwrap().parse().unwrap();
                let val: i64 = iter.next().unwrap().parse().unwrap();
                seg.range_add(left, right, val);
            }
            2 => {
                let left: usize = iter.next().unwrap().parse().unwrap();
                let right: usize = iter.next().unwrap().parse().unwrap();
                writeln!(out, "{}", seg.range_sum(left, right)).unwrap();
            }
            _ => unreachable!(),
        }
    }
}
