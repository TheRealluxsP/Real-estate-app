//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#include "Date.h"

Date::Date(const std::string& date, const std::string& hour) : date(date), hour(hour) {}

std::string Date::getDate() const {
    return date;
}

std::string Date::getHour() const {
    return hour;
}
