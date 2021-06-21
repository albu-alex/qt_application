//
// Created by SL15 on 21.06.2021.
//

#include "ProgrammerRepository.h"

bool ProgrammerRepository::add(const Programmer &programmer) {
    for(auto p : this->programmers)
        if(p == programmer)
            return false;
    this->programmers.push_back(programmer);
    return true;
}

void ProgrammerRepository::load_from_file() {
    std::ifstream input("D:\\clion_projects\\qt_application\\programmers.txt");
    if(!input.is_open())
        throw std::runtime_error("File could not open correctly!");
    Programmer new_programmer;
    while(!input.eof() && input >> new_programmer)
        this->add(new_programmer);
    input.close();
}

void ProgrammerRepository::save_to_file() {
    std::ofstream output("D:\\clion_projects\\qt_application\\programmers.txt");
    if(!output.is_open())
        throw std::runtime_error("File could not open correctly!");
    for(const auto& programmer:this->programmers)
        if(&programmer == &this->programmers.back())
            output << programmer;
        else
            output << programmer << std::endl;
    output.close();
}

std::vector<Programmer> ProgrammerRepository::get_programmers() const {
    return this->programmers;
}
