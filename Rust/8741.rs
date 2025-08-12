fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let k: i32 = inbuf.trim().parse().unwrap();

    for _ in 0..k {
        print!("1");
    }
    for _ in 0..k-1 {
        print!("0");
    }
}
