// TODO: I don't understand the question

pub fn gcd_of_strings(str1: String, str2: String) -> String {
    let rl: String = format!("{}{}", str1, str2);
    let lr: String = format!("{}{}", str2, str1);
    if rl != lr{
        return String::from("");
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}

// str1 = "ABCDEF"
// str2 = "ABC"
// Should be: ""