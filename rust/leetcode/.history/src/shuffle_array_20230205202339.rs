pub struct Solution;
impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for i as usize in 0..n{
            res.push(nums[i]);
        }

        res
    }
}