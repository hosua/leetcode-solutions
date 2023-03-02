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

        if row == num_rows {

        }
        
    }

    fn upstate(i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

    }
}