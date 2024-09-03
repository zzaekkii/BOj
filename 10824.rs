fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let numbers: Vec<&str> = inbuf.trim().split_whitespace().collect();

    let a: i64 = numbers[0].parse::<i64>().unwrap() * 10_i64.pow(numbers[1].len() as u32) + numbers[1].parse::<i64>().unwrap();

    let b: i64 = numbers[2].parse::<i64>().unwrap() * 10_i64.pow(numbers[3].len() as u32) + numbers[3].parse::<i64>().unwrap();

    println!("{}", a + b);
}
