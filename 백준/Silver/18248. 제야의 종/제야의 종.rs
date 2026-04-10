use std::io::{self, Read, Write};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_ascii_whitespace();

    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();

    let mut heard = vec![vec![0u8; m]; n];
    for i in 0..n {
        for j in 0..m {
            heard[i][j] = iter.next().unwrap().parse().unwrap();
        }
    }

    let mut result = true;

    for i in 0..n {
        for k in (i + 1)..n {
            let mut i_has_k_not = false;
            let mut k_has_i_not = false;

            for j in 0..m {
                if heard[i][j] == 1 && heard[k][j] == 0 {
                    i_has_k_not = true;
                }
                if heard[i][j] == 0 && heard[k][j] == 1 {
                    k_has_i_not = true;
                }
            }

            if i_has_k_not && k_has_i_not {
                result = false;
                break;
            }
        }

        if !result {
            break;
        }
    }

    let mut out = io::BufWriter::new(io::stdout().lock());
    writeln!(out, "{}", if result { "YES" } else { "NO" }).unwrap();
}

