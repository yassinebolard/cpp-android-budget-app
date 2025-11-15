//
// Created by yass on 11/14/25.
//

#include "transaction.hpp"

[[nodiscard]] bool Transaction::operator==(const Transaction& other) const noexcept {
    return this->m_description == other.m_description &&
           this->m_amount_cents == other.m_amount_cents &&
           this->m_date == other.m_date;
}