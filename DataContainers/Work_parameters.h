//
// Created by jakubb on 10.02.2022.
//

#ifndef FILECOUNTER_WORK_PARAMETERS_H
#define FILECOUNTER_WORK_PARAMETERS_H


#include <string>
#include <thread>
#include <filesystem>
#include <iostream>
class Work_parameters {
private:
    std::filesystem::path path;
    int thread;
    bool benchmarks;
    bool count_empty_notempty;
    bool count_world;
    bool count_letter;
public:
    Work_parameters();

public:
    const std::filesystem::path & getPath() const;

    void setPath(const std::string &path);

    bool isCountLetter() const;

    void setCountLetter(bool countLetter);

    int getThread() const;

    void setThread(int thread);

    bool isBenchmarks() const;

    void setBenchmarks(bool benchmarks);

    bool isCountEmptyNotempty() const;

    void setCountEmptyNotempty(bool countEmptyNotempty);

    bool isCountWorld() const;

    void setCountWorld(bool countWorld);

};


#endif //FILECOUNTER_WORK_PARAMETERS_H
