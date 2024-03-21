use std::{fs, io::{self, BufRead, Write}, path::Path};

pub fn run_file(path: &Path) {
    let bytes = fs::read(path).unwrap();
    let content = String::from_utf8(bytes).unwrap();
    run(&content);
}

pub fn run_prompt() -> io::Result<()> {
    let stdin = io::stdin();
    let mut reader = stdin.lock();

    loop {
        print!("> ");
        io::stdout().flush();

        let mut line = String::new();
        match reader.read_line(&mut line)  {
            Ok(0) => break,
            Ok(_) => {
                line = line.trim().to_string();
                run(&line);
            }
            Err(err) => return Err(err),
        }
    }

    Ok(())
}

pub fn run(source: &str) {
    let mut scanner =  Scanner::new(source);
    let tokens = scanner.scan_tokens();

    for token in tokens {
        println!("{:?}", token);
    }
}