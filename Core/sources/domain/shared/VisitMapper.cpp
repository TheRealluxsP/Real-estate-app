//
// Created by Rui Pedro Monteiro on 04/12/2024.
//

#include "VisitMapper.h"
#include <sstream>
#include <iomanip>

VisitDTO VisitMapper::convertToDTO(const Visit& visit) {
    // Convert date to string in "dd-MM-yyyy hh:mm" format
    stringstream dateStream;
    dateStream << std::setw(2) << std::setfill('0') << visit.getDate().getDay() << "-"
               << std::setw(2) << std::setfill('0') << visit.getDate().getMonth() << "-"
               << visit.getDate().getYear() << " "
               << std::setw(2) << std::setfill('0') << visit.getDate().getHour() << ":"
               << std::setw(2) << std::setfill('0') << visit.getDate().getMinute();
    string dateString = dateStream.str();

    return VisitDTO(dateString, visit.getStatus());
}

Visit VisitMapper::convertToDomain(const VisitDTO& dto) {
    // Convert string date to Date object (assume Date class handles parsing)
    Date date(dto.getDate());  // Assume Date has a constructor that takes a string in the format "dd-MM-yyyy hh:mm"
    return Visit(0, date);  // Use 0 as placeholder for visitId
}
