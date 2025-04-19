//
// Created by Utilizador on 12/01/2025.
//

#ifndef STOREDTO_H
#define STOREDTO_H
#include <string>

using namespace std;

class StoreDTO {
public:
    wstring code;
    string designation;
    float revenue;

    StoreDTO(const wstring& code, const string& designation, float revenue): code(code), designation(designation), revenue(revenue) {};
};

#endif //STOREDTO_H
