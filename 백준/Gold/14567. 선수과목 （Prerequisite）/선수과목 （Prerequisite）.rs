use std::{
    collections::VecDeque,
    io::{self, Read, Write},
};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut course = vec![Vec::<usize>::new(); n + 1];
    let mut cnt = vec![0usize; n + 1];
    for _ in 0..m {
        let a: usize = iter.next().unwrap().parse().unwrap();
        let b: usize = iter.next().unwrap().parse().unwrap();

        course[a].push(b);
        cnt[b] += 1;
    }

    let mut q = VecDeque::<usize>::new();
    for i in 1..=n {
        if cnt[i] == 0 {
            q.push_back(i);
        }
    }

    let mut ans = vec![1usize; n + 1];
    while let Some(cur) = q.pop_front() {
        for &nxt in &course[cur] {
            cnt[nxt] -= 1;
            ans[nxt] = ans[nxt].max(ans[cur] + 1);

            if cnt[nxt] == 0 {
                q.push_back(nxt);
            }
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    for i in 1..=n {
        write!(out, "{} ", ans[i]).unwrap();
    }
}
