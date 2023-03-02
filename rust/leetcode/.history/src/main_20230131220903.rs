mod gcd_of_strings;

fn main() {
    println!("Hello, world!");
    let res: String = gcd_of_strings::gcd_of_strings(String::from("abcabc"), String::from("abc"));
    println!("res: {}", res);
}
