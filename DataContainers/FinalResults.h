//
// Created by jakubb on 14.02.2022.
//

#ifndef FILECOUNTER1_FINALRESULTS_H
#define FILECOUNTER1_FINALRESULTS_H
#include <atomic>
#include <iostream>

class FinalResults {
private:
    std::atomic<int> fileCount;
    std::atomic<int> emptyLineCount;
    std::atomic<int> noEmptyLineCount;
    std::atomic<int> word;
    std::atomic<int> character;
public:
    friend class Search_directory;
    void show();
    void zero();
    FinalResults();
};


#endif //FILECOUNTER1_FINALRESULTS_H
