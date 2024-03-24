use token::Token;
use token::TokenType;
use token::TokenLiteral;

#[derive(Debug)]
struct Scanner<'a> {
    source: &'a str,
    tokens: Vec<Token<'a>>,
    start: i32,
    current: i32,
    line: i32,
}

impl<'a> Scanner<'a> {
    fn new(source: &'a str) -> Self {
        Scanner {
            source,
            tokens: Vec::new(),
            start: 0,
            current: 0,
            line: 1,
        }
    }

    fn scan_tokens(&mut self) -> Vec<Token> {
        while !self.is_at_end() {
            let start = self.current;
            self.scan_token();
        }
    
        self.tokens.push(Token::new(TokenType::EOF, "", None, self.line));
        self.tokens
    }

    fn is_at_end(&self) -> bool {
        self.current >= self.source.len().try_into().unwrap()
    }

    fn scan_token(&mut self) {
        let c = self.advance();
        match c {
            Some('(') => self.add_token(TokenType::LeftParen),
            Some(')') => self.add_token(TokenType::RightParen),
            Some('{') => self.add_token(TokenType::LeftBrace),
            Some('}') => self.add_token(TokenType::RightParen),
            Some(',') => self.add_token(TokenType::COMMA),
            Some('.') => self.add_token(TokenType::DOT),
            Some('-') => self.add_token(TokenType::MINUS),
            Some('+') => self.add_token(TokenType::PLUS),
            Some(';') => self.add_token(TokenType::SEMICOLON),
            Some('*') => self.add_token(TokenType::STAR),
            Some(_) => (),
        }
    }

    fn advance(&mut self) -> Option<char> {
        let current_char = self.peek();
        if current_char.is_some() {
            self.current += current_char.unwrap().len_utf8();
        }
        current_char
    }

    fn add_token(&mut self, r#type: TokenType) {
        self.add_token_with_literal(r#type, None);
    }

    fn add_token_with_literal(&mut self, r#type: TokenType, literal: Option<TokenLiteral<'a>>) {
        let text = &self.source[self.start..self.current];
        self.tokens.push(Token::new(r#type, text, literal, self.line));
    }

    fn peek(&self) -> Option<char> {
        self.source[self.current..].chars().next()
    }


}


