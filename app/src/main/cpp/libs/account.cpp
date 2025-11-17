//
// Created by yass on 11/14/25.
//

#include "account.hpp"
#include <algorithm>
#include <string>
#include <format>

void Account::addTransaction(const Transaction& new_transaction) noexcept {
    // Add the transaction to the log.
    this->m_transactions.push_back(new_transaction);

    // Update the balance.
    this->deposit(new_transaction.getAmountCents());
}

void Account::removeTransaction(const Transaction& r_transaction) {
    auto position = std::find(this->m_transactions.begin(), this->m_transactions.end(), r_transaction);

    if (position != this->m_transactions.end()) {
        // We use withdraw() because it correctly does (balance - amount)
        this->withdraw(position->getAmountCents());
        this->m_transactions.erase(position);
    }
    // If not found (else block), do nothing. It's not an error.
}