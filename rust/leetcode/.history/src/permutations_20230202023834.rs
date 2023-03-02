use std::vec::Vec;

pub struct Solution;

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        fn helper(n: usize, res: &mut Vec<Vec<i32>>, nums: &Vec<i32>){
            if n == 1 {
                res.push(&nums);
            }
            for i in 0..n {
                helper(n-1, res, nums);
            }
        }

        vec![]
    }

}