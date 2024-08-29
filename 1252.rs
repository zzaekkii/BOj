fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let mut iter = inbuf.split_whitespace();
    let a = iter.next().unwrap();
    let b = iter.next().unwrap();

    let sum = i128::from_str_radix(a, 2).unwrap() + i128::from_str_radix(b, 2).unwrap();

    println!("{:b}", sum);
}
