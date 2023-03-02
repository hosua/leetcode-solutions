mod gcd_of_strings;

fn main() {
    println!("Hello, world!");
    let sol: gcd_of_strings::Solution = gcd_of_strings::new();
    sol.gcd_of_strings("abcd", "aefg");
}
