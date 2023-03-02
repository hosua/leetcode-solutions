use std::collections::HashMap;

pub struct Solution;
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut mp: HashMap<char, usize> = HashMap::new();
        order.chars().enumerate().map(|x| x.0 + x.1);
        for (i, ch) in order.chars().enumerate() {
            mp.insert(ch, i);
        }

        for 
        false
    }
}