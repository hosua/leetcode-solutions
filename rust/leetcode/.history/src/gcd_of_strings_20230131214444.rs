pub struct Solution {
    
}

impl Solution {
    pub fn new() -> Self { Solution{} }

    pub fn gcd_of_strings(self: &Self, str1: String, str2: String) -> String {
        Self::substrings(str2, "".to_string());
        return "".to_string();    
    }

    fn substrings(self: &Self, input: String, output: String){
        if (input.is_empty()){
            println!("{} ", output);
            return;
        }

        let mut next: String = output.clone();
        next.push(input.chars().nth(0).unwrap());
        substrings(input[1..].to_string(), next.to_string());
        substrings(input[1..].to_string(), output);
    }
}