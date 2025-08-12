fn fibo(n: i32) -> i32 {
    if n <= 1 {
        n
    } else {
        fibo(n - 2) + fibo(n - 1)
    }
}

fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).expect("😏");
    println!("{}", fibo(inbuf.trim().parse().unwrap()));
}
