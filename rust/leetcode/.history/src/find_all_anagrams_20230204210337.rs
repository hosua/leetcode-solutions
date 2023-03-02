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
            let p_: usize = p.chars.nth(i).unwrap();
        }

        for i in P..S {

        }

        res
    }
}