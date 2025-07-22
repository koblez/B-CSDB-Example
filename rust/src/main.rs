use std::io;
use std::io::Write;

fn main() {
    let mut input = String::new();
    print!("Input: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).unwrap();
    println!("{}", input.trim());
}
