//
// Created by Rui Pedro Monteiro on 02/12/2024.
//

#ifndef DHMS_VISIT_H
#define DHMS_VISIT_H

#include "Date.h"
#include "VisitDTO.h"

class Visit {
private:
    int visitId;
    Date date;
    string status;

public:
    Visit(int visitId, const Date& date, const string& status);

    int getVisitId() const;
    void setVisitId(int visitId);

    Date getDate() const;
    void setDate(const Date& date);

    string getStatus() const;
    void setStatus(const string& status);

    // Conversion of DTO
    VisitDTO toDTO() const;
    static Visit fromDTO(const VisitDTO& dto);
};

#endif // DHMS_VISIT_H


