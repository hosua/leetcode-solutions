pub struct Solution;
use std::vec::Vec;

const ALPHA: usize = 26;

impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let mut res: Vec<i32> = vec![];
        let S: usize = s.len();        
        let P: usize = p.len();
        
        let s_bytes = s.as_bytes();
        let mut p_count: Vec<usize> = vec![0; ALPHA];
        let mut s_count: Vec<usize> = vec![0; ALPHA];

        for i in 0..P {
            let p_: usize = (p.chars().nth(i).unwrap().to_digit(10).unwrap() - 'a'.to_digit(10).unwrap()) as usize;
            let s_: usize = (s.chars().nth(i).unwrap().to_digit(10).unwrap() - 'a'.to_digit(10).unwrap()) as usize;
            println!("{} {}", p_, s_);
            p_count[p_] += 1;
            s_count[s_] += 1;
        }

        // if p_count == s_count {
        //     res.push(0);
        // }

        // for i in P..S {
        //     let start: usize = i-P;
        //     let end: usize = i+1;
        //     p_count[start] -= 1;
        //     p_count[end] += 1;
        //     if p_count == s_count {
        //         res.push(i as i32);
        //     }
        // }

        res
    }
}