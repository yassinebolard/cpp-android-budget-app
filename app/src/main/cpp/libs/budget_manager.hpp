//
// Created by yass on 11/14/25.
//

#ifndef BUDGETAPP_BUDGET_MANAGER_HPP
#define BUDGETAPP_BUDGET_MANAGER_HPP

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdint>
#include "account.hpp"
#include "transaction.hpp"

class BudgetManager {
    private:
        std::map<std::string, Account> m_accounts; // Map of all the accounts with the name of it as key

    public:
        /* Constructor / Destructor */
        BudgetManager() = default;
        explicit BudgetManager(std::map<std::string, Account> map) : m_accounts{std::move(map)} {};
        virtual ~BudgetManager() = default;

        bool createAccount(const std::string& init_name, Account::account_type_t init_type, int64_t initial_balance_cents);
        [[nodiscard]] Account* getAccount(std::string name) const;
        [[nodiscard]] std::vector<std::string> listAccountNames() const;
        void addTransactionToAccount(std::string name, int64_t amount_cents, std::string description, std::chrono::system_clock::time_point date);
        [[nodiscard]] std::vector<Transaction> getTransactionsForAccount(std::string name) const;
        [[nodiscard]] int64_t getAccountBalance(std::string name) const;


};

#endif // BUDGETAPP_BUDGET_MANAGER_HPP
