pub struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let mut matrix: Vec<Vec<String>> = vec![];
        matrix.resize(num_rows);

        let mut res: String;        

        down_state(0, 0, num_rows as usize, s, matrix);
        res
    }
    fn down_state(i: usize, row: usize, col: usize, num_rows: usize, input: String, matrix: &mut Vec<Vec<String>>){
        if i == input.size() {
            return;
        }

        let ch = input.chars().nth(i).unwrap();
        // matrix[row].push()

        if row == num_rows {

        }
    }

    fn up_state(i: usize, row: usize, col: usize, num_rows: usize, input: String, matrix: &mut Vec<Vec<String>>){
        if i == input.size(){
            return;
        }
    }

}