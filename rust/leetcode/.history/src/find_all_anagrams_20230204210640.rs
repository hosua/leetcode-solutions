pub struct Solution;
use std::vec::Vec;

const ALPHA: usize = 26;

impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let mut res: Vec<i32>;
        const S: usize = s.len();        
        const P: usize = p.len();

        let mut p_count: Vec<usize> = vec![0; ALPHA];
        let mut s_count: Vec<usize> = vec![0; ALPHA];

        for i in P {
            let p_: usize = p.chars.nth(i).unwrap() - 'a'.to_digit(10);
            let s_: usize = s.chars.nth(i).unwrap() - 'a'.to_digit(10);
            p_count[p_] += 1;
            s_count[s_] += 1;
        }

        if p_count == s_count {
            res.push(i);
        }

        for i in P..S {
            let start: usize = i-P;
            let end: usize;
            if p_count == s_count {
                res.push(i);
            }
        }

        res
    }
}