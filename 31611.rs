fn main(){
    let mut inbuf = String::new();
    std::io::stdin()
        .read_line(&mut inbuf)
        .expect("😏");
    
    let num: Vec<i32> = inbuf
        .as_mut_str()
        .split_whitespace()
        .map(|inbuf| inbuf.parse().unwrap())
        .collect();
    
    let ans = if num[0]%7==2 {1} else {0};
    println!("{:?}",ans);
}
