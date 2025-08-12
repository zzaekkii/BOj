use std::io::{self, *};

fn main() {    
    let stdout = io::stdout();
    let mut stdout = io::BufWriter::new(stdout.lock());
    
    let mut inbuf = String::new();
    std::io::stdin().read_line(&mut inbuf).unwrap();

    let ch = inbuf.trim().chars().next().unwrap();

    write!(stdout, "{}", match ch {
        'N' | 'n' => "Naver D2",
        _ => "Naver Whale",
    }).unwrap();
}
