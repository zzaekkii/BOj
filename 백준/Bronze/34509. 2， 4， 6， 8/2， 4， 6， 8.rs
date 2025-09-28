use std::io::{self, Write};

fn main(){
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    out.write_all(b"42").unwrap();
}