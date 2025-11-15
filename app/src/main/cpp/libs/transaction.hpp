//
// Created by yass on 11/14/25.
//

#ifndef BUDGETAPP_TRANSACTION_HPP
#define BUDGETAPP_TRANSACTION_HPP

#include <string>
#include <cstdint>
#include <chrono>
#include <utility>

class Transaction {
    private:
        int64_t m_amount_cents;
        std::string m_description;
        std::chrono::system_clock::time_point m_date;

    public:
        /* Constructor / Destructor */
        Transaction() = delete; // A transaction MUST have data
        explicit Transaction(int64_t amount_cents, std::string description, std::chrono::system_clock::time_point date) : m_amount_cents{amount_cents}, m_description{std::move(description)}, m_date{date} {};
        virtual ~Transaction() = default;

        [[nodiscard]] int64_t getAmountCents() const noexcept { return this->m_amount_cents; };
        [[nodiscard]] std::string getDescription() const noexcept { return this->m_description; };
        [[nodiscard]] std::chrono::system_clock::time_point getDate() const noexcept { return this->m_date; };
        [[nodiscard]] bool operator==(const Transaction& other) const noexcept;
};

#endif //BUDGETAPP_TRANSACTION_HPP
