struct Solution;
impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        return "".to_string();    
    }

    fn substrings(input: String, output: String){
        if (input.is_empty()){
            println!("{} ", output);
            return;
        }

        let mut next: String = output;
        output.push(input.chars().nth(0));
        Self::substrings(input[1..].to_string(), output);
    }
}