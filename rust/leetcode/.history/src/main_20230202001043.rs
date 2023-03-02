mod alien_dictionary;
fn main() {
    let sol: alien_dictionary::Solution;
    let words: Vec<String> = vec![String::from("hello"), String::from("leetcode")];
    let order = String::from("hlabcdefgijkmnopqrstuvwxyz");
    sol.is_alien_sorted(words, order);
}
