pub struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut res: String = String::new();     
        Self::helper(s.len()-1, &mut res);
        s
    }

    fn helper(i: usize, sub: &mut String){

    }
}