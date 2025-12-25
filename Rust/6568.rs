use std::io::{self, Read, Write};

const OPERAND_MASK: u8 = 0b0001_1111;

// 🎅🎄

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let mut out = io::BufWriter::new(io::stdout().lock());

    loop {
        let mut mem = [0u8; 32];

        for i in 0..32 {
            let s = match iter.next() {
                Some(s) => s,
                None => return,
            };

            let bytes = s.as_bytes();
            for &c in bytes {
                mem[i] = mem[i] * 2 + (c - b'0');
            }
        }

        let mut pc = 0usize;
        let mut acc = 0u8;

        loop {
            let opcode = mem[pc] >> 5;
            let operand = (mem[pc] & OPERAND_MASK) as usize;

            pc = (pc + 1) % 32;

            match opcode {
                0 => { // STA
                    mem[operand] = acc;
                }
                1 => { // LDA
                    acc = mem[operand];
                }
                2 => { // BEQ
                    if acc == 0 {
                        pc = operand;
                    }
                }
                3 => { // NOP }
                4 => { // DEC
                    acc = acc.wrapping_sub(1);
                }
                5 => { // INC
                    acc = acc.wrapping_add(1);
                }
                6 => { // JMP
                    pc = operand;
                }
                7 => { // HLT
                    break;
                }
                _ => unreachable!(),
            }
        }

        writeln!(out, "{:08b}", acc).unwrap();
    }
}
