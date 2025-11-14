//
// Created by yass on 11/14/25.
//

#ifndef BUDGETAPP_ACCOUNT_HPP
#define BUDGETAPP_ACCOUNT_HPP

#pragma once

#include <iostream>
#include <string>
#include <cstdint>

class Account{
    public:
        enum class account_type_t : uint8_t {
            CHECKING,
            SAVINGS
        };

        const account_type_t DEFAULT_ACCOUNT_TYPE = account_type_t::CHECKING;

    private:
        /* Attributes */
        std::string m_name;
        int64_t m_balance;
        account_type_t m_type{DEFAULT_ACCOUNT_TYPE};

        /* Private functions to change values of attributes */
        void set_name(std::string new_name) noexcept { this->m_name = std::move(new_name); };
        void set_balance(int64_t new_balance) noexcept { this->m_balance = new_balance; };
        void set_type(account_type_t new_type) noexcept { this->m_type = new_type; };

    public:
        /* Constructor / Destructor */
        Account() = default;
        explicit Account(std::string name, int64_t balance, account_type_t type) : m_name{std::move(name)}, m_balance{balance}, m_type{type} {};
        virtual ~Account() = default;

        [[nodiscard]] std::string getName() const noexcept { return this->m_name; };
        [[nodiscard]] int64_t getBalance() const noexcept { return this->m_balance; };
        [[nodiscard]] account_type_t getType() const noexcept { return this->m_type; };
        void deposit(int64_t amount) noexcept;
        void withdraw(int64_t amount) noexcept;
};

#endif //BUDGETAPP_ACCOUNT_HPP
