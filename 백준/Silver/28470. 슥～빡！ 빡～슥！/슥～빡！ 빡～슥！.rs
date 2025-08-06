fn main() {
    let (n, inc, dec, chg) = inputs();
    let mut total = 0i64;

    for i in 0..n {
        let atk_first = inc[i] * chg[i] / 10 - dec[i];
        let def_first = inc[i] - dec[i] * chg[i] / 10;

        total += atk_first.max(def_first);
    }

    println!("{}", total);
}

fn inputs() -> (usize, Vec<i64>, Vec<i64>, Vec<i64>) {
    use std::io::{self, Read};
    let mut inbuf = String::new();
    io::stdin().read_to_string(&mut inbuf).unwrap();

    let lines: Vec<&str> = inbuf.lines().collect();

    let n: usize = lines[0].parse().unwrap();

    let inc: Vec<i64> = lines[1]
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let dec: Vec<i64> = lines[2]
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let chg: Vec<i64> = lines[3]
        .split_whitespace()
        .map(|x| {
            let f: f64 = x.parse().unwrap();
            (f * 10.0) as i64
        })
        .collect();

    (n, inc, dec, chg)
}