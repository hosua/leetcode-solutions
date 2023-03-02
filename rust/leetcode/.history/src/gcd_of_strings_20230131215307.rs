pub struct Solution {
    
}

impl Solution {
    pub fn new() -> Self { Solution{} }

    pub fn gcd_of_strings(self: &Self, str1: String, str2: String) -> String {
        let subs: &mut Vec<String> = &mut Vec::new();
        self.substrings(str2, String::from(""), subs);

        for sub in subs {
            println!("{} ", sub);
            if str1.contains(sub.to_string()) {

            }
        }

        return "".to_string();    
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