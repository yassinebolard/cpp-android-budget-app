//
// Created by yass on 11/14/25.
//

#include "budget_manager.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <chrono>
#include <utility>

bool BudgetManager::createAccount(const std::string& init_name, Account::account_type_t init_type, int64_t initial_balance_cents) {
    if (this->m_accounts.contains(init_name)) {
        std::string errorMessage = std::format("Account name {} already registered.", init_name);
        throw std::invalid_argument(errorMessage);
        return false;
    } else {
        Account new_account = Account(init_name, initial_balance_cents, init_type);
        this->m_accounts.insert({init_name, new_account});
        return true;
    }
}


