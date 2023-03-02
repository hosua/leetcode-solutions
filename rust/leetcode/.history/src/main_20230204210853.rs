mod find_all_anagrams;
fn main() {
    let s: String = String::from("cbaebabacd");
    let p: String = String::from("abc");
    let res: Vec<i32> = find_all_anagrams::Solution::find_anagrams(s, p);
}
