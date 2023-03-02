pub struct Solution {
    
}

impl Solution {
    pub fn new() -> Self { Solution{} }

    pub fn gcd_of_strings(self: &Self, str1: String, str2: String) -> String {
        Vec<String> subs;
        self.substrings(str2, String::from(""), subs);
        return "".to_string();    
    }

    fn substrings(self: &Self, input: String, output: String, subs: Vec<String>){
        if (input.is_empty()){
            println!("{} ", output);
            return;
        }

        let mut next: String = output.clone();
        next.push(input.chars().nth(0).unwrap());
        self.substrings(input[1..].to_string(), next.to_string());
        self.substrings(input[1..].to_string(), output);
    }
}