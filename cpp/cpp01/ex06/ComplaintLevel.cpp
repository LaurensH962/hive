#include "ComplaintLevel.hpp"

ComplaintLevel findComplaintLevel(const std::string& str){
    if (str == "DEBUG")
        return ComplaintLevel::DEBUG;
    if (str == "INFO")
        return ComplaintLevel::INFO;
    if ((str == "WARNING"))
        return ComplaintLevel::WARNING;
    if ((str == "ERROR"))
        return ComplaintLevel::ERROR;
    return (ComplaintLevel::NOTHING);
}