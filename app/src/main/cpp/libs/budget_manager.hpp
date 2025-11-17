//
// Created by yass on 11/14/25.
//

#ifndef BUDGETAPP_BUDGET_MANAGER_HPP
#define BUDGETAPP_BUDGET_MANAGER_HPP

#include <string>
#include <map>
#include <vector> // Changed from <utility>
#include <cstdint>
#include "account.hpp"
#include "transaction.hpp"

class BudgetManager {
private:
    // Map of all the accounts with the name of it as key
    std::map<std::string, Account> m_accounts;

public:
    /* Constructor / Destructor */
    BudgetManager() = default;
    explicit BudgetManager(std::map<std::string, Account> map) : m_accounts{std::move(map)} {};
    virtual ~BudgetManager() = default;

    [[nodiscard]] bool createAccount(const std::string& init_name, Account::account_type_t init_type, int64_t initial_balance_cents);

    /**
     * @brief Gets a *modifiable* pointer to an account.
     */
    [[nodiscard]] Account* getAccount(const std::string& name) noexcept;

    /**
     * @brief Gets a *read-only* pointer to an account.
     */
    [[nodiscard]] const Account* getAccount(const std::string& name) const noexcept;
    [[nodiscard]] std::vector<std::string> listAccountNames() const noexcept;
    [[nodiscard]] bool addTransactionToAccount(const std::string& account_name, int64_t amount_cents, const std::string& description);
    [[nodiscard]] const std::vector<Transaction>& getTransactionsForAccount(const std::string& account_name) const;
    [[nodiscard]] int64_t getAccountBalance(const std::string& account_name) const noexcept;
};

#endif // BUDGETAPP_BUDGET_MANAGER_HPP