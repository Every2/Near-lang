use std::env;
use scanner::{run_file, run_prompt};

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
