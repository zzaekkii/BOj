const NUMBER: [[&str; 5]; 10] = [
    // 0.
    [
        "***",
		"* *",
		"* *",
		"* *",
		"***"
    ],
    // 1.
    [
		"  *",
		"  *",
		"  *",
		"  *",
		"  *"
    ],
    // 2.
    [
        "***",
        "  *",
        "***",
        "*  ",
        "***"
    ],
    // 3.
    [
        "***",
        "  *",
        "***",
        "  *",
        "***"
    ],
    // 4.
    [
        "* *",
        "* *",
        "***",
        "  *",
        "  *"
    ],
    // 5.
    [
        "***",
        "*  ",
        "***",
        "  *",
        "***"
    ],
    // 6.
    [
        "***",
        "*  ",
        "***",
        "* *",
        "***"
    ],
    // 7.
    [
        "***",
        "  *",
        "  *",
        "  *",
        "  *"
    ],
    // 8.
    [
        "***",
        "* *",
        "***",
        "* *",
        "***"
    ],
    // 9.
    [
        "***",
        "* *",
        "***",
        "  *",
        "***"
    ],
];

fn main(){
    let inbuf = inputs();
    match decode(inbuf) {
        Ok(code) => {
            if code % 6 == 0 {
                println!("BEER!!");
            } else {
                println!("BOOM!!");
            }
        }
        Err(_) => {
            println!("BOOM!!");
        }
    }
}

fn inputs() -> Vec<Vec<char>> {
    use std::io::{self, BufRead};
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let mut result = Vec::new();
    for _ in 0..5 {
        let line = lines.next().unwrap().unwrap();
        let row: Vec<char> = line
            .chars()
            .collect();
        result.push(row);
    }

    result
}

fn decode(data: Vec<Vec<char>>) -> Result<i32, String> {
    let width = data[0].len();
    let mut result = 0;

    for i in (0..width-2).step_by(4) {
        let mut recognized = false;
        
        let digit_block: Vec<String> = (0..5)
            .map(|row| data[row][i..i+3].iter().collect())
            .collect();

        for (digit, pattern) in NUMBER.iter().enumerate() {
            if digit_block == pattern {
                result = result * 10 + digit as i32;
                recognized = true;
                break;
            }
        }

        if !recognized {
            // println!("인식 불가능한 숫자 블록 at {}!\n", i);
            return Err(format!("인식 불가!"))
        }
    }
    
    // println!("{:?}\n", result);

    Ok(result)
}