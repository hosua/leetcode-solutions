mod zigzag_conversion;
mod longest_palindrome;

fn main() {
    let s: String = String::from("PAYPALISHIRING");
    let num_rows = 3;

    let res = zigzag_conversion::Solution::convert(s, num_rows);
    println!("res: {}", res);
}
