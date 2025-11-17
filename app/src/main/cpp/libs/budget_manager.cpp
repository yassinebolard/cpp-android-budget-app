//
// Created by yass on 11/14/25.
//

#include "budget_manager.hpp"
#include <chrono> // For system_clock::now()

/**
 * @brief Creates an account *in-place* in the map.
 * This is the most efficient way (C++17). No copies.
 */
bool BudgetManager::createAccount(const std::string& init_name,
                                  Account::account_type_t init_type,
                                  int64_t initial_balance_cents) {
    auto [iterator, success] = this->m_accounts.try_emplace(init_name,
                                                            init_name, // Arg 1 for Account constructor
                                                            initial_balance_cents, // Arg 2
                                                            init_type); // Arg 3
    return success;
}

/**
 * @brief The non-const version of getAccount.
 * Used when we need to *modify* the account.
 */
Account* BudgetManager::getAccount(const std::string& name) noexcept {
    auto it = this->m_accounts.find(name);
    if (it == this->m_accounts.end()) {
        return nullptr;
    } else {
        return &(it->second); // Returns a modifiable Account*
    }
}

/**
 * @brief The const version of getAccount.
 * Used when we only need to *read* from the account.
 */
const Account* BudgetManager::getAccount(const std::string& name) const noexcept {
    auto it = this->m_accounts.find(name);
    if (it == this->m_accounts.end()) {
        return nullptr;
    } else {
        return &(it->second); // Returns a read-only const Account*
    }
}

/**
 * @brief List all the accounts
 */
[[nodiscard]] std::vector<std::string> BudgetManager::listAccountNames() const noexcept{
    std::vector<std::string> listAccount;
    listAccount.reserve(this->m_accounts.size()); // Good optimization!
    for (const auto& pair : this->m_accounts) {
        listAccount.push_back(pair.first);
    }
    return listAccount;
}

/**
 * @brief Adds a transaction.
 */
bool BudgetManager::addTransactionToAccount(const std::string& account_name, int64_t amount_cents, const std::string& description) {
    Account* account_ptr = this->getAccount(account_name);

    if (account_ptr == nullptr) {
        return false; // Account not found
    } else {
        // Create the transaction using the current time
        Transaction new_transaction = Transaction(amount_cents,
                                                  description,
                                                  std::chrono::system_clock::now());

        account_ptr->addTransaction(new_transaction);
        return true;
    }
}

/**
 * @brief Returns a *reference* (no copy) to the transaction vector.
 * Throws an exception if the account is not found.
 */
const std::vector<Transaction>& BudgetManager::getTransactionsForAccount(const std::string& account_name) const {
    // We call the *const* getAccount() because this function *is* const.
    const Account* account_ptr = this->getAccount(account_name);

    if (account_ptr == nullptr) {
        throw std::runtime_error("Account not found");

    } else {
        return account_ptr->getTransactions(); // Returns a const&
    }
}

/**
 * @brief Gets the balance.
 */
[[nodiscard]] int64_t BudgetManager::getAccountBalance(const std::string& account_name) const noexcept {
    const Account* account_ptr = this->getAccount(account_name);

    if (account_ptr == nullptr) {
        return 0; // Return 0 if not found
    } else {
        return account_ptr->getBalance();
    }
}