use token::Token;

#[derive(Debug)]
struct Scanner<'a> {
    source: &'a str,
    tokens: Vec<Token<'a>>,
}

impl<'a> Scanner<'a> {
    fn new(source: &'a str) -> Self {
        Scanner {
            source,
            tokens: Vec::new(),
        }
    }
}