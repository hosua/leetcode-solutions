mod shuffle_array;
fn main() {
    let nums = vec![2,5,1,3,4,7];
    let n = 3;
    shuffle_array::Solution::shuffle(nums, n);
}
