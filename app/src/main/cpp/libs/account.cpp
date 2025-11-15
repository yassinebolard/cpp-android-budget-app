//
// Created by yass on 11/14/25.
//

#include "account.hpp"
#include <algorithm>
#include <string>

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

void Account::addTransaction(const Transaction& new_transaction) noexcept {
    auto position = std::find(this->m_transactions.begin(), this->m_transactions.end(), new_transaction);
    if (position == this->m_transactions.end()) {
        this->m_transactions.insert(this->m_transactions.end(), new_transaction);
        this->deposit(new_transaction.getAmountCents());
    }
};

void Account::removeTransaction(const Transaction& r_transaction) {
    auto position = std::find(this->m_transactions.begin(), this->m_transactions.end(), r_transaction);
    if (position != this->m_transactions.end()) {
        // Adjust the balance before removing the transaction
        // We subtract the transaction's amount
        this->withdraw(r_transaction.getAmountCents());

        // Erase the transaction from the vector
        this->m_transactions.erase(position);
    } else {
        std::string errorMessage = std::format("Transaction {} of {} doesn't exist in the account", r_transaction.getDescription(), r_transaction.getAmountCents());
        throw std::invalid_argument(errorMessage);
    }
};