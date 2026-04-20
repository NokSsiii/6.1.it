#pragma once

class Object {
private:
    static unsigned int count;
public:
    Object();
    Object(const Object&);
    virtual ~Object();
    static unsigned int GetCount();
};