use std::collections::HashMap;

pub struct Solution;


// return false if prev not previous to next
fn compare_words(next: String, prev: String, mp: HashMap<char, usize>) -> bool {
    let mut i = 0;
    while next.chars().nth(i) == prev.chars().nth(i) {
        i += 1;
    }

    let a = *mp.get(&prev.chars().nth(i).unwrap()).unwrap();
    let b = *mp.get(&next.chars().nth(i).unwrap()).unwrap();

    return if a < b { true } else { false };
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
            compare_words(*word, prev, mp);
        }

        false
    }
}