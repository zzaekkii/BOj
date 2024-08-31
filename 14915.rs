fn to_base_n(mut m: u32, n: u32) -> String {
    if m == 0 {
        return "0".to_string();
    }

    let mut result = String::new();

    while m > 0 {
        let remainder = (m % n) as u8;
        
        let digit = if remainder < 10 {
            (b'0' + remainder) as char
        } else {
            (b'A' + (remainder - 10)) as char
        };
        result.push(digit);
        m /= n;
    }

    result.chars().rev().collect()
}

fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let mut iter = inbuf.split_whitespace();
    let m: u32 = iter.next().unwrap().parse().unwrap();
    let n: u32 = iter.next().unwrap().parse().unwrap();

    println!("{}", to_base_n(m, n));
}
