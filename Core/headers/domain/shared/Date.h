//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_GETAGENTLISTCONTROLLER_H
#define DHMS_GETAGENTLISTCONTROLLER_H

#include <string>

class Date {
private:
    std::string date; // Date in YYYY-MM-DD format
    std::string hour; // Time in HH:MM format

public:
    // Constructor
    Date(const std::string& date, const std::string& hour);

    // Getters
    std::string getDate() const;
    std::string getHour() const;
};

#endif // DHMS_GETAGENTLISTCONTROLLER_H
