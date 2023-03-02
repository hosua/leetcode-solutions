use std::collections::HashMap;

pub struct Solution;


fn compare_words(a: String, prev: String, mp: HashMap<char, usize>) -> bool {
    let mut i = 0;
    while a.chars().nth(i) == prev.chars().nth(i) {
        i += 1;
    }
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