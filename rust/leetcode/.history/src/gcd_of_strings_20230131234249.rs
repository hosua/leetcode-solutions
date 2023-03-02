// TODO: I don't understand the question

pub fn gcd_of_strings(str1: String, str2: String) -> String {
    let rl: String = format!("{}{}", str1, str2);
    let lr: String = format!("{}{}", str2, str1);

    if rl != lr{
        return String::from("");
    }

    let gcd_len: i32 = gcd(str1.len() as i32, str2.len() as i32);
    return &str1[0..gcd_len];
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