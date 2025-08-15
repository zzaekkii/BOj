use std::io::{self, Read, Write};

fn main() {
    let mut sc = Scanner::new();
    let mut out = io::BufWriter::new(io::stdout());

    let t = sc.next();
    for _ in 0..t {
        let r = sc.next();
        let c = sc.next();

        if r == c {
            writeln!(out, "dohoon").unwrap();
        } else {
            writeln!(out, "jinseo").unwrap();

            let tmp = if r > c { c } else { r };
            writeln!(out, "{} {}", tmp, tmp).unwrap();
        }
    }
}

struct Scanner {
    buf: Vec<u8>,
    pos: usize,
}

impl Scanner {
    fn new() -> Self {
        let mut buf = Vec::new();
        io::stdin().read_to_end(&mut buf).unwrap();
        Self { buf, pos: 0 }
    }

    #[inline]
    fn next(&mut self) -> usize {
        let mut num: usize = 0;

        while self.pos < self.buf.len() && self.buf[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }

        while self.pos < self.buf.len() && self.buf[self.pos].is_ascii_digit() {
            num = num * 10 + (self.buf[self.pos] - b'0') as usize;
            self.pos += 1;
        }

        num
    }
}