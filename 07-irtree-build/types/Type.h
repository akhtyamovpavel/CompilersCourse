#pragma once

class Type {
 public:
    virtual int ToInt();
    virtual ~Type() = default;
};