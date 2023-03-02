pub struct Solution;
use std::vec::Vec;

const ALPHA: usize = 26;

impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let mut res: Vec<i32> = vec![];
        let S: usize = s.len();        
        let P: usize = p.len();
        
        let s_bytes = s.as_bytes();
        let p_bytes = p.as_bytes();
        let mut p_count: Vec<usize> = vec![0; ALPHA];
        let mut s_count: Vec<usize> = vec![0; ALPHA];

        for i in 0..P {
            let p_ = (p_bytes[i] as u32 - 'a' as u32) as usize;
            let s_ = (s_bytes[i] as u32 - 'a' as u32) as usize;
            // println!("{} {}", p_, s_);
            p_count[p_] += 1;
            s_count[s_] += 1;
        }

        if p_count == s_count {
            res.push(0);
        }

        for i in P..S {
            let start = (s_bytes[i-P] - 'a' as u8) as usize;
            let end = (s_bytes[i] - 'a' as u8) as usize;
            s_count[start] -= 1;
            s_count[end] += 1;
            if p_count == s_count {
                res.push(i - (P as i32) as i32);
            }

            println!("p_count: {:?}", p_count);
            println!("s_count: {:?}", s_count);
            println!();
        }

        res
    }
}