use std::collections::HashMap;

// pub struct Solution;
// impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut mp: HashMap<char, usize> = HashMap::new();

        order.chars()
            .enumerate()
            .map(|x| mp.insert(x.1, x.0));
        for (k,v) in mp {
            println!("{} {}", k, v);
        }
        false
    }
// }