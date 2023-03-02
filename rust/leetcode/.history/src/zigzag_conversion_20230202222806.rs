pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 { return s; }
        let mut res: String = String::new();
        let mut mat: Vec<String> = Vec::new();
        
        res
    }

    fn downstate(i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

        let ch = input.chars().nth(i);

        if row == num_rows {
            Self::upstate(i+1, row-1, num_rows, input, mat);
        } else {
            Self::downstate(i+1, row+1, num_rows, input, mat);
        }
        
    }

    fn upstate(i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

    }
}