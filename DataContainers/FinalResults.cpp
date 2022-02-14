//
// Created by jakubb on 14.02.2022.
//

#include "FinalResults.h"

FinalResults::FinalResults() {
    fileCount=0;
    emptyLineCount=0;
    noEmptyLineCount=0;
    character=0;
    word=0;
}

void FinalResults::show() {
    std::cout<<"File :"<< fileCount<<std::endl;
    std::cout<<"No empty line :"<< noEmptyLineCount<<std::endl;
    std::cout<<"Empty :"<< emptyLineCount<<std::endl;
    std::cout<<"Word :"<< word<<std::endl;
    std::cout<<"Character :"<< character<<std::endl;
}

void FinalResults::zero() {
    fileCount=0;
    noEmptyLineCount=0;
    emptyLineCount=0;
    word=0;
    character=0;
}
