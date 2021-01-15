
use std::env;
use std::process;
use std::fs;
use std::io::Result;

fn compile(input:String) -> Result<&'static str> {
    println!("compile stub: {}", input);
    Ok("helo")
}

fn main() {
    let args:Vec<String> = env::args().collect();
    
    if args.len() != 2 {
        eprintln!("nitrogen: expected a single commandline argument.");
        process::exit(1);
    }

    let file = &args[1];

    if let Ok(contents) = fs::read_to_string(file) {
        let status = compile(contents);
    }
}
