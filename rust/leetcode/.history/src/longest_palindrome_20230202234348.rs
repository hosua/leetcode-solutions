pub struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let s: String = String::new();     
        helper(s.size()-1, String::from("")) ;

        s
    }

    fn helper(i: usize, sub: String){

    }
}