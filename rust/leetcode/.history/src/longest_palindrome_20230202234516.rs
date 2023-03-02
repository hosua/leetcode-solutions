pub struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let res: String = String::new();     
        Self::helper(s.len()-1, String::from(""));
        s
    }

    fn helper(i: usize, sub: String){

    }
}