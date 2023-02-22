use std::io;
use std::process::ExitCode;

fn main() -> ExitCode {
    let mut buf = String::new();
    io::stdin()
        .read_line(&mut buf)
        .expect("Failed to read line from stdin");

    // why u8? check the doc.
    const MAGIC_NUMBER: u8 = 42;
    let number: u8 = buf.trim().parse().expect("Input is not a valid u8.");

    if number == MAGIC_NUMBER {
        return ExitCode::from(number);
    }

    return ExitCode::SUCCESS;
}
