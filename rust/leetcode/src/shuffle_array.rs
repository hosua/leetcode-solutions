pub struct Solution;
impl Solution {
    // rust-ier solution
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        nums[..n as usize]
            .iter()
            .zip(nums[n as usize..].iter())
            .flat_map(|(&x, &y)| vec![x,y])
            .collect()
    }
    // my intuition
    // pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
    //     let mut res: Vec<i32> = Vec::new();
    //     for i in 0..n as usize {
    //         res.push(nums[i]);
    //         res.push(nums[n as usize + i]);
    //     }
    //     res
    // }
}