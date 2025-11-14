//
// Created by yass on 11/14/25.
//

#include "account.hpp"

void Account::deposit(int64_t amount) noexcept {
    int64_t balance = this->getBalance();
    balance = balance + amount;

    this->set_balance(balance);
};

void Account::withdraw(int64_t amount) noexcept {
    int64_t balance = this->getBalance();
    balance = balance - amount;

    this->set_balance(balance);
};
