fn main() {
    let mut inbuf: String = String::new();
    std::io::stdin().read_line(&mut inbuf).expect("😏");

    let num: Vec<i32> = inbuf
        .split_whitespace()
        .map(|s| s.trim().parse().expect("😏"))
        .collect();

    if (num[0] + num[1]) == num[2] {
        println!("correct!");
    } else {
        println!("wrong!");
    }
}
