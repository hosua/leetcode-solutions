pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 { return s; }
        let mut res: String = String::new();
        let mut mat: Vec<String> = Vec::new();
        mat.resize(num_rows as usize, String::from(""));

        Self::helper(false, 0, 0, num_rows as usize, s, &mut mat);
        for word in mat.iter() {
            for ch in word.chars() {
                res.push(ch);
            }
        }
        res
    }
    fn helper(up: bool, i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

        let ch = input.chars().nth(i).unwrap();
        mat[row].push(ch);

        if (up){
            if row == 0 {
                Self::helper(false, i+1, row+1, num_rows, input, mat);
            } else {
                Self::helper(true, i+1, row-1, num_rows, input, mat);
            } 

        } else {
            if row == num_rows-1 {
                Self::helper(true, i+1, row-1, num_rows, input, mat);
            } else {
                Self::helper(false, i+1, row+1, num_rows, input, mat);
            }
        }
    }
}