mod gcd_of_strings;

fn main() {
    let res: String = gcd_of_strings::gcd_of_strings(String::from("ababab"), String::from("abab"));
    println!("res: {}", res);
}
