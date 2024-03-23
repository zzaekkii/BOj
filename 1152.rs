use std::io::{stdin, Read};
fn main() {
    let mut inbuf = String::new();
    stdin().read_to_string(&mut inbuf).expect("😏");
    println!("{}", inbuf.split_ascii_whitespace().count());
}
