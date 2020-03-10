#pragma once

class Object {
 public:
    virtual int ToInt();
    virtual ~Object() = default;
};