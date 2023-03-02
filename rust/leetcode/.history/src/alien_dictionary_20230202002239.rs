use std::collections::HashMap;

pub struct Solution;

fn foo(a: String, b: String) -> bool {
    false
}

impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut mp: HashMap<char, usize> = HashMap::new();
        for (i, ch) in order.chars().enumerate(){
            mp.insert(ch, i);
        }

        let mut sorted_vec: Vec<String> = words.clone();
        sorted_vec.sort_by(|a, b| foo(a.to_string(),b.to_stirng()));
        false
    }
}