#include "Object.h"

unsigned int Object::count = 0;

Object::Object() { count++; }
Object::Object(const Object&) { count++; }
Object::~Object() { count--; }
unsigned int Object::GetCount() { return count; }