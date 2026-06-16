impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        if (ransom_note.len() > magazine.len()) {
            return false;
        }

        let mut letters = [0i32; 26];

        for c in magazine.bytes() {
            let idx = (c - b'a') as usize;
            letters[idx] += 1;
        }

        for c in ransom_note.bytes() {
            let idx = (c - b'a') as usize;
            letters[idx] -= 1;

            if (letters[idx] < 0) {
                return false;
            }
        }

        return true;
    }
}
