use std::cmp::max;

fn main() {
    let mut coordinates = Vec::new();
    let stdin = std::io::stdin();

    for _ in 0..3 {
        let mut line = String::new();
        stdin.read_line(&mut line).unwrap();

        let nums: Vec<i32> = line
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        coordinates.push((nums[0], nums[1]));
    }

    let (x1, y1) = coordinates[0];
    let (x2, y2) = coordinates[1];
    let (x3, y3) = coordinates[2];

    let b = max((x3 - x1).abs(), (y3 - y1).abs());
    let d = (x3 - x2).abs() + (y3 - y2).abs();

    println!(
        "{}",
        if b == d {
            "tie"
        } else if b > d {
            "daisy"
        } else {
            "bessie"
        }
    );
}
