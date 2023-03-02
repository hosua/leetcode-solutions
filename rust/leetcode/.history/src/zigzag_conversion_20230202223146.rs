pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 { return s; }
        let mut res: String = String::new();
        let mut mat: Vec<String> = Vec::new();

        Self::downstate(0, 0, num_rows as usize, s, &mut mat);

        for i in 0..mat.len(){
            for ch in mat[i]{

            }
        }
        res
    }

    fn downstate(i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

        let ch = input.chars().nth(i).unwrap();
        mat[row].push(ch);

        if row == num_rows-1 {
            Self::upstate(i+1, row-1, num_rows, input, mat);
        } else {
            Self::downstate(i+1, row+1, num_rows, input, mat);
        }
    }

    fn upstate(i: usize, row: usize, num_rows: usize, input: String, mat: &mut Vec<String>){
        if i == input.len(){ return; }

        let ch = input.chars().nth(i).unwrap();
        mat[row].push(ch);

        if row == 0 {
            Self::downstate(i+1, row+1, num_rows, input, mat);
        } else {
            Self::upstate(i+1, row-1, num_rows, input, mat);
        } 
    }
}