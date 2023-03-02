mod alien_dictionary;
fn main() {
    let words: Vec<String> = vec![String::from("hello"), String::from("hello")];
    let order = String::from("hlabcdefgijkmnopqrstuvwxyz");
    // let words: Vec<String> = vec![String::from("hello"), String::from("leetcode")];
    // let order = String::from("hlabcdefgijkmnopqrstuvwxyz");
    // let words: Vec<String> = vec![String::from("word"), String::from("world"), String::from("row")];
    // let order = String::from("worldabcefghijkmnpqstuvxyz");
    let res = alien_dictionary::Solution::is_alien_sorted(words, order);
    println!("res: {}", res);
}
