//
// Created by jakubb on 10.02.2022.
//

#include "Work_parameters.h"

const std::filesystem::path &Work_parameters::getPath() const {
    return path;
}

void Work_parameters::setPath(const std::string &path) {
    if(path.empty())Work_parameters::path=std::filesystem::current_path();
    Work_parameters::path = path;
    std::cout<<Work_parameters::path<<std::endl;
}

int Work_parameters::getThread() const {
    return thread;
}

void Work_parameters::setThread(int thread) {
    if(thread>=std::thread::hardware_concurrency())Work_parameters::thread=std::thread::hardware_concurrency()-1;
    else Work_parameters::thread = thread;
}

bool Work_parameters::isBenchmarks() const {
    return benchmarks;
}

void Work_parameters::setBenchmarks(bool benchmarks) {
    Work_parameters::benchmarks = benchmarks;
}

bool Work_parameters::isCountEmptyNotempty() const {
    return count_empty_notempty;
}

void Work_parameters::setCountEmptyNotempty(bool countEmptyNotempty) {
    count_empty_notempty = countEmptyNotempty;
}

bool Work_parameters::isCountWorld() const {
    return count_world;
}

void Work_parameters::setCountWorld(bool countWorld) {
    count_world = countWorld;
}

bool Work_parameters::isCountLetter() const {
    return count_letter;
}

void Work_parameters::setCountLetter(bool countLetter) {
    count_letter = countLetter;
}

Work_parameters::Work_parameters():path(""),thread(1),benchmarks(false),count_letter(false),count_world(false),
                                   count_empty_notempty(false) {
    if(path.empty())Work_parameters::path=std::filesystem::current_path();
    Work_parameters::path = path;
}
