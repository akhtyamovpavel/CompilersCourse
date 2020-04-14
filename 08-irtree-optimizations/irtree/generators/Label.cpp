//
// Created by akhtyamovpavel on 4/7/20.
//

#include "Label.h"
IRT::Label::Label(): label_("L" + std::to_string(counter_++)) {
}

IRT::Label::Label(std::string label): label_(label) {

}
std::string IRT::Label::ToString() const {
    return label_;
}

int IRT::Label::counter_ = 0;

