use std::env;
use std::{fs, io::{self, BufRead, Write}, path::Path};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() > 1 {
        println!("Usage: Near[script]");
        std::process::exit(64);
    } else if args.len() == 1 {
        if let Err(e) = run_file(&args[0]) {
            eprintln!("Error: {}", e);
            std::process::exit(1);
        }
    } else {
        run_prompt();
    }
}



fn run_file(path: &Path) {
    let bytes = fs::read(path).unwrap();
    let content = String::from_utf8(bytes).unwrap();
    run(&content);
}

fn run_prompt() -> io::Result<()> {
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

fn run(source: &str) {
    let mut scanner =  Scanner::new(source);
    let tokens = scanner.scan_tokens();

    for token in tokens {
        println!("{:?}", token);
    }
}