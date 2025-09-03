#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other){
    std::cout << "Brain copy constructor called" << std::endl;
    int i = 0;
    for (const auto& idea : other._ideas)
        _ideas[i++] = idea;
}

Brain& Brain::operator=(const Brain& other){
    std::cout << "Brain copy assignment operator called" << std::endl;
    if(this != &other){
        int i = 0;
        for (const auto& idea : other._ideas)
            this->_ideas[i++] = idea;
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "";
}