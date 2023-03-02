use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut mp: HashMap<char, usize> = HashMap::new();
        for (i, ch) in order.chars().enumerate(){
            mp.insert(ch, i);
        }

        let mut sorted_vec: Vec<String> = words.clone();
        sorted_vec.sort_by(|a, b| Self::foo(a,b));
        false
    }

    fn foo(a: String, b: String) -> bool {
        false
    }
}