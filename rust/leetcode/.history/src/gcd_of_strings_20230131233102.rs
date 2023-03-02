// TODO: I don't understand the question

pub fn gcd_of_strings(str1: String, str2: String) -> String {
    let gcd_len: i32 = gcd(str1.len() as i32, str2.len() as i32);
    println!("len gcd: {}", gcd_len);

    let mut shorter: String = String::new();
    let mut longer: String = String::new();
    if str1.len() < str2.len() {
        longer = str2.clone();
        shorter = str1.clone();
    } else {
        longer = str1.clone();
        shorter = str2.clone();
    }

    let mut subs: Vec<String> = Vec::new();
    check_sub(shorter, gcd_len as usize, &mut subs);

    let mut longest_sub: String = String::new();
    for s in subs.iter() {
        if (longer.contains(s)){

        }
        print!("{} ", s);
    }
    return String::from("");
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}

fn check_sub(s: String, sz: usize, v: &mut Vec<String> ) {
    for i in 0..s.len()-sz+1{
        let sub: String = s[i..i+sz].to_string();
        v.push(sub);
    }
}