use std::io::{self, BufRead, Write};

fn main() {
    for line in io::stdin().lock().lines() {
        let n: usize = line.unwrap().trim().parse().unwrap();

        let mut dp = vec![String::new(); 3];

        dp[0] = "1".to_string();
        dp[1] = "1".to_string();
        dp[2] = "3".to_string();

        for i in 3..=n {
            dp[i % 3] = calculate_string(&dp[(i - 1) % 3], &dp[(i - 2) % 3]);
        }

        writeln!(io::stdout().lock(), "{}", dp[n % 3]).unwrap();
    }
}

// dp[i] = dp[i-1] + dp[i-2] * 2
fn calculate_string(x: &String, y: &String) -> String {
    let y = mul2(y);
    add(x, &y)
}

fn mul2(x: &String) -> String {
    let mut carry = 0;
    let mut result = String::new();

    let x_bytes = x.as_bytes();
    let mut x_idx = x.len() as isize - 1;

    while x_idx >= 0 || carry > 0 {
        let digit = if x_idx >= 0 {
            x_bytes[x_idx as usize] - b'0'
        } else {
            0
        };

        let prod = digit * 2 + carry;
        result.push(((prod % 10) + b'0') as char);
        carry = prod / 10;

        x_idx -= 1;
    }

    result.chars().rev().collect()
}

fn add(x: &String, y: &String) -> String {
    let mut carry = 0;
    let mut result = String::new();

    let x_bytes = x.as_bytes();
    let y_bytes = y.as_bytes();
    
    let mut x_idx = x.len() as isize - 1;
    let mut y_idx = y.len() as isize - 1;

    while x_idx >= 0 || y_idx >= 0 || carry > 0 {
        let nx = if x_idx >= 0 {
            x_bytes[x_idx as usize] - b'0'
        } else {
            0
        };

        let ny = if y_idx >= 0 {
            y_bytes[y_idx as usize] - b'0'
        } else {
            0
        };

        let sum = nx + ny + carry;
        result.push(((sum % 10) + b'0') as char);
        carry = sum / 10;

        x_idx -= 1;
        y_idx -= 1;
    }

    result.chars().rev().collect()
}
