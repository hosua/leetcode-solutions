mod gcd_of_strings;

fn main() {
    println!("Hello, world!");
    let mnut sol: gcd_of_strings::Solution = gcd_of_strings::Solution::new();
    sol.gcd_of_strings(String::from("abcd"), String::from("aefg"));
}
