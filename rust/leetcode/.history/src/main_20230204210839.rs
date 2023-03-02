mod find_all_anagrams;
fn main() {
    let s: String = String::from("cbaebabacd");
    let p: String = String::from("abc");
    find_all_anagrams::Solution::find_anagrams(s, p)
}
