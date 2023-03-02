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

        let mut prev = &words[0];

        for i in 1..words.len() {
            let word = &words[i];

        }
        false
    }
}