fn main(){
    let mut a = String::new();
    std::io::stdin()
        .read_line(&mut a)
        .expect("😏");
    
    let mut b = String::new();
    std::io::stdin()
        .read_line(&mut b)
        .expect("😏");
    
    let a: i32 = a
        .trim()
        .parse()
        .unwrap();
    
    let b: i32 = b
        .trim()
        .parse()
        .unwrap();
    
    println!("{}",a+b+3);
}
