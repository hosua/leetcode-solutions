pub struct Solution {
}

impl Solution {
    pub fn new() -> Self { Solution {} }

    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let mut longest_str: String = String::new();
        let mut subs: Vec<String> = Vec::new();
        Self::substrings(, str2, String::from(""), &mut subs);

        for sub in subs.iter() {
            // println!("{} ", sub);
            if str1.contains(&sub.to_string()) {
                if longest_str.len() < sub.len() {
                    longest_str = sub.clone();
                }
            }
        }
        
        return longest_str.to_string();    
    }

    fn substrings(self: &Self, input: String, output: String, subs: &mut Vec<String>){
        if (input.is_empty()){
            subs.push(output);
            return;
        }

        let mut next: String = output.clone();
        next.push(input.chars().nth(0).unwrap());
        self.substrings(input[1..].to_string(), next.to_string(), subs);
        self.substrings(input[1..].to_string(), output, subs);
    }
}