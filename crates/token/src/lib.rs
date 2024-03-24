#[derive(Debug)]
pub struct Token<'a> {
    r#type: TokenType,
    lexeme: &'a str,
    literal: TokenLiteral<'a>,
    line: i32,
}

#[derive(Debug)]
pub enum TokenLiteral<'a> {
    StringLiteral(&'a str),
    NumberLiteral(f64),
    Identifier(&'a str)
}

#[derive(Debug)]
pub enum TokenType {
    // Single-character tokens.
    LeftParen, RightParen, LeftBrace, RightBrace,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BangEqual,
    EQUAL, EqualEqual,
    GREATER, GreaterEqual,
    LESS, LessEqual,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    EOF
}


impl<'a> std::fmt::Display for Token<'a> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let type_str = match &self.r#type {
            TokenType::IDENTIFIER => "IDENTIFIER".to_string(),
            TokenType::STRING => "STRING".to_string(),
            TokenType::AND => "AND".to_string(),
            TokenType::BANG => "BANG".to_string(),
            TokenType::BangEqual => "BANG_EQUAL".to_string(),
            TokenType::CLASS => "CLASS".to_string(),
            TokenType::COMMA => "COMMA".to_string(),
            TokenType::DOT => "DOT".to_string(),
            TokenType::ELSE => "ELSE".to_string(),
            TokenType::EOF => "EOF".to_string(),
            TokenType::EQUAL => "EQUAL".to_string(),
            TokenType::EqualEqual => "EQUAL_EQUAL".to_string(),
            TokenType::FALSE => "FALSE".to_string(),
            TokenType::FOR => "FOR".to_string(),
            TokenType::FUN => "FUN".to_string(),
            TokenType::GREATER => "GREATER".to_string(),
            TokenType::GreaterEqual => "GREATER_EQUAL".to_string(),
            TokenType::IF => "IF".to_string(),
            TokenType::LESS => "LESS".to_string(),
            TokenType::LessEqual => "LESS_EQUAL".to_string(),
            TokenType::LeftBrace => "LeftBrace".to_string(),
            TokenType::LeftParen => "LeftParen".to_string(),
            TokenType::MINUS => "MINUS".to_string(),
            TokenType::NIL => "NIL".to_string(),
            TokenType::NUMBER => "NUMBER".to_string(),
            TokenType::OR => "OR".to_string(),
            TokenType::PLUS => "PLUS".to_string(),
            TokenType::PRINT => "PRINT".to_string(),
            TokenType::RETURN => "RETURN".to_string(),
            TokenType::RightBrace => "RightBrace".to_string(),
            TokenType::RightParen => "RightParen".to_string(),
            TokenType::SEMICOLON => "SEMICOLON".to_string(),
            TokenType::SLASH => "SLASH".to_string(),
            TokenType::STAR => "STAR".to_string(),
            TokenType::SUPER => "SUPER".to_string(),
            TokenType::THIS => "THIS".to_string(),
            TokenType::TRUE => "TRUE".to_string(),
            TokenType::VAR => "VAR".to_string(),
            TokenType::WHILE => "WHILE".to_string(),
            _ => "UNKNOWN".to_string(), 
        };
        write!(f, "{} {} {:?}", type_str, self.lexeme, self.literal)
    }
}

impl<'a> Token<'a> {
    pub fn new(r#type: TokenType, lexeme: &'a str, literal: TokenLiteral<'a>, line: i32) -> Self {
        Token {
            r#type,
            lexeme,
            literal,
            line,
        }
    }
}
