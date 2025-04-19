//
// Created by Rui Pedro Monteiro on 02/12/2024.
//
#include "Visit.h"
#include "VisitDTO.h"

Visit::Visit(int visitId, const Date& date, const string& status) : visitId(visitId), date(date), status(status) {}

int Visit::getVisitId() const {
    return visitId;
}

void Visit::setVisitId(int visitId) {
    this->visitId = visitId;
}

Date Visit::getDate() const {
    return date;
}

void Visit::setDate(const Date& date) {
    this->date = date;
}

string Visit::getStatus() const {
    return status;
}

void Visit::setStatus(const string& status) {
    this->status = status;
}

VisitDTO Visit::toDTO() const {
    return VisitMapper::convertToDTO(*this);
}

Visit Visit::fromDTO(const VisitDTO& dto) {
    return VisitMapper::convertToDomain(dto);
}
