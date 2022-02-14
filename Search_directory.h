//
// Created by jakubb on 10.02.2022.
//

#ifndef FILECOUNTER_SEARCH_DIRECTORY_H
#define FILECOUNTER_SEARCH_DIRECTORY_H

#include "DataContainers/FinalResults.h"
#include "DataContainers/Work_parameters.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <thread>
#include <list>
#include <vector>
#include <mutex>
#include <cwctype>
#include "atomic"

class Search_directory {
private:
    const Work_parameters workParameters;
    static FinalResults results;
    static std::filesystem::recursive_directory_iterator dir_entry;
    static std::mutex iteratorMutex;
public:
    void show();
    explicit Search_directory(const Work_parameters &workParameters);
    static void searchFile(Work_parameters workParameters, int id);
    static void searchLine(Work_parameters &workParameters,std::filesystem::path path);
    void startSearch(int threadNum=0);
    void benchmark();
};




#endif //FILECOUNTER_SEARCH_DIRECTORY_H
