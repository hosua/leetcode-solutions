use std::vec::Vec;

pub struct Solution;

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        fn helper(n: usize, res: &mut Vec<Vec<i32>>, nums: &mut Vec<i32>){
            if n == 1 {
                res.push(nums.clone());
            }
            for i in 0..n {
                helper(n-1, res, nums);
                if n % 2 == 0 {
                    nums.swap(i, n-1);
                } else {
                    nums.swap(0, n-1);
                }
            }
        }
        helper(nums.len() as usize, &mut res, &mut nums);
        res
    }

}