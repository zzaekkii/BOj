fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let mut numbers = inbuf
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap());

    let sum: i32 = numbers.by_ref().take(4).sum();
    let n = numbers.next().unwrap();

    let ans = if sum < 4 * n { 4 * n - sum } else { 0 };

    println!("{}", ans);
}
