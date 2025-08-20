#pragma once

#include <string>

enum class ComplaintLevel{
    DEBUG, 
    INFO, 
    WARNING, 
    ERROR,
    NOTHING
};

ComplaintLevel findComplaintLevel(const std::string& str);