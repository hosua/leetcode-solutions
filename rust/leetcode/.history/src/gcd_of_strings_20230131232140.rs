// TODO: I don't understand the question
pub fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}

pub fn gcd_of_strings(str1: String, str2: String) -> String {
    let gcd_len: i32 = gcd(str1.len() as i32, str2.len() as i32);
    return String::from("");
}