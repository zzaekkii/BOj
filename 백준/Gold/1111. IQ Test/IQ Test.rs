use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    let mut out = io::BufWriter::new(io::stdout().lock());

    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut arr = vec![0; n];
    for i in 0..n {
        arr[i] = iter.next().unwrap().parse().unwrap();
    }

    if n == 1 {
        writeln!(out, "A").unwrap();
        return;
    }

    if n == 2 {
        if arr[0] == arr[1] {
            writeln!(out, "{}", arr[0]).unwrap();
        } else {
            writeln!(out, "A").unwrap();
        }
        return;
    }

    let diff1 = arr[1] - arr[0];
    let diff2 = arr[2] - arr[1];

    let a_opt = if diff1 == 0 {
        if diff2 != 0 {
            writeln!(out, "B").unwrap();
            return;
        }
        None
    } else {
        if diff2 % diff1 != 0 {
            write!(out, "B").unwrap();
            return;
        }
        Some(diff2 / diff1)
    };

    let b = if let Some(a) = a_opt {
        arr[1] - arr[0] * a
    } else {
        let val = arr[0];
        for i in 1..n {
            if arr[i] != val {
                writeln!(out, "B").unwrap();
                return;
            }
        }
        writeln!(out, "{}", val).unwrap();
        return;
    };

    let a = a_opt.unwrap();

    for i in 3..n {
        if arr[i] != arr[i - 1] * a + b {
            writeln!(out, "B").unwrap();
            return;
        }
    }

    writeln!(out, "{}", arr[n - 1] * a + b).unwrap();
}