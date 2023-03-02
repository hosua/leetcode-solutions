mod zigzag_conversion;

fn main() {
    let s: String = String::from("PAYPALISHIRING");
    let num_rows = 3;

    zigzag_conversion::Solution::convert(s, num_rows);
}
