use std::collections::HashMap;

pub struct Solution;
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mp: HashMap<char, usize> = HashMap::new();
        for (i, ch) in order.chars().enumerate() {
            mp.insert(ch, i);
        }
        false
    }
}