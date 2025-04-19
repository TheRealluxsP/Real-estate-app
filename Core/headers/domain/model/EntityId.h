//
// Created by siulo on 30/12/2024.
//

#ifndef DHMS_ENTITYID_H
#define DHMS_ENTITYID_H

#include <string>

using namespace std;

class EntityId {
private:
    wstring value;

protected:
    EntityId(const wstring &value);

    virtual void setValue(const wstring &value);

    virtual bool isValueValid(const wstring &value) = 0;

public:
    const wstring &getValue() const;

    virtual bool operator==(const EntityId &other) const;

    virtual bool operator<(const EntityId &other) const;
};


#endif //DHMS_ENTITYID_H
