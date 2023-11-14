#include <iostream>
#include <memory>
#include "Token/token.hpp"

class Expr {

public: 
    virtual ~Expr() = default;
};

class Binary: public Expr {

public:
    Binary(std::unique_ptr<Expr> left, Token operatorToken, std::unique_ptr<Expr> right) : left(std::move(left)), operatorToken(operatorToken), right(std::move(right)) {}

    const std::unique_ptr<Expr> left;
    const Token operatorToken;
    const std::unique_ptr<Expr> right;
};