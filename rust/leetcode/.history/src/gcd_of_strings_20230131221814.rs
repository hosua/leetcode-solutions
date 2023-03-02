pub fn gcd_of_strings(str1: String, str2: String) -> String {
    let mut longest_str: String = String::new();
    let mut subs: Vec<String> = Vec::new();
    substrings(str2, String::from(""), &mut subs);

    for sub in subs.iter() {
        // println!("{} ", sub);
        if str1.contains(&sub.to_string()) {
            let mut check: &mut String = sub.clone();
            check.push_str(&check);
            if longest_str.len() < sub.len() {
                longest_str = sub.clone();
            }
        }
    }
    
    return longest_str.to_string();    
}

fn substrings(input: String, output: String, subs: &mut Vec<String>){
    if (input.is_empty()){
        subs.push(output);
        return;
    }

    let mut next: String = output.clone();
    next.push(input.chars().nth(0).unwrap());
    substrings(input[1..].to_string(), next.to_string(), subs);
    substrings(input[1..].to_string(), output, subs);
}
