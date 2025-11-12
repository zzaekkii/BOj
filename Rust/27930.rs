use std::io;

fn main() {
    let input = io::read_to_string(io::stdin()).unwrap();
    let str = input.as_bytes();

    let mut kdx = 0;
    let mut ydx = 0;
    let korea = b"KOREA";
    let yonsei = b"YONSEI";

    let klen = korea.len();
    let ylen = yonsei.len();

    for &ch in str {
        if ch == korea[kdx] {
            kdx += 1;
        }

        if ch == yonsei[ydx] {
            ydx += 1;
        }

        if kdx == klen {
            println!("KOREA");
            return;
        }

        if ydx == ylen {
            println!("YONSEI");
            return;
        }
    }
}
