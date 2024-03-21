static mut HAD_ERROR: bool = false;

pub fn error(line: usize, message: &str) {
    report(line, "", message);
}

pub fn report(line: usize, where_: &str, message: &str) {
    unsafe  {
        eprintln!("[line {}] Error{}:  {}", line, where_, message);
        HAD_ERROR = true;
    }
}