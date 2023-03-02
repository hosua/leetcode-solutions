mod gcd_of_strings;

fn main() {
    println!("Hello, world!");
    let res: String = sol.gcd_of_strings(String::from("abcabc"), String::from("abc"));
    println!("res: {}", res);
}
