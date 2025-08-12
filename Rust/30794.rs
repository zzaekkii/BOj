fn main() {
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let parts: Vec<&str> = inbuf.split_whitespace().collect();

    let lv:i32 = parts[0].parse().unwrap();
    let ver = parts[1];

    let score = match ver {
        "miss" => 0,
        "bad" => 200,
        "cool" => 400,
        "great" => 600,
        "perfect" => 1000,
        _ => -1,
    };

    println!("{}", lv * score);
}
