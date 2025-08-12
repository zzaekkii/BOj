fn is_vowel(c: char) -> bool {
    matches!(c, 'a' | 'e' | 'i' | 'o' | 'u')
}

fn main() {
    let mut inbuf = String::new();
    while std::io::stdin().read_line(&mut inbuf).is_err() {
        println!("Input error!");
    }

    let trimmed_inbuf = inbuf.trim();

    // 초기값: 0, 모음: 1, 자음: 2.
    let mut prev = 0;
    let mut flag = true;

    for c in trimmed_inbuf.chars() {
        let is_vowel = is_vowel(c);
        
        if is_vowel && prev == 1 || !is_vowel && prev == 2 {
            flag = false;
            break;
        }
        prev = if is_vowel { 1 } else { 2 };
    }
    
    println!("{}", match flag {
        true => 1,
        false => 0,
    });
}
