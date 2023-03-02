mod find_all_anagrams;
fn main() {
    let s: String = String::from("cbaebabacd");
    let p: String = String::from("abc");
    // let s = String::from("aaaaaaaaaa");
    // let p = String::from("aaaaaaaaaaaaa");
    let res: Vec<i32> = find_all_anagrams::Solution::find_anagrams(s, p);
    for num in res.iter(). {
        println!("{}", num);
    }
}
