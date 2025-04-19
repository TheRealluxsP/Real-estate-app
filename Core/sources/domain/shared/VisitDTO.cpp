//
// Created by Rui Pedro Monteiro on 04/12/2024.
//

#include "VisitDTO.h"

VisitDTO::VisitDTO(const string& date, const string& status) : date(date), status(status) {}

string VisitDTO::getDate() const {
    return date;
}

void VisitDTO::setDate(const string& date) {
    this->date = date;
}

string VisitDTO::getStatus() const {
    return status;
}

void VisitDTO::setStatus(const string& status) {
    this->status = status;
}