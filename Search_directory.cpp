//
// Created by jakubb on 10.02.2022.
//


#include "Search_directory.h"

FinalResults Search_directory::results;
std::filesystem::recursive_directory_iterator Search_directory::dir_entry;
std::mutex Search_directory::iteratorMutex;

void Search_directory::startSearch(int threadNum) {
    std::vector<std::jthread*> threadPool;
    try {
        dir_entry = std::filesystem::recursive_directory_iterator(workParameters.getPath());
    }
    catch (std::filesystem::filesystem_error e)
    {
        throw e;
    }
    if(threadNum==0)threadNum=workParameters.getThread();
    for(int i = 0;i<threadNum;i++ ){
        threadPool.push_back(new std::jthread(searchFile,workParameters,i));
    }

    while(!threadPool.empty()){
        std::jthread* t = threadPool.back();
        threadPool.pop_back();
        t->join();
        delete t;
    }
}

void Search_directory::searchFile(Work_parameters workParameters, int id) {
    std::filesystem::path path;
    while(true) {
        if(dir_entry==end(dir_entry)) return;
        iteratorMutex.lock();
        while(dir_entry!=end(dir_entry)){
            if(dir_entry->is_regular_file()){
                path = dir_entry->path();
                dir_entry++;
                results.fileCount++;
                break;
            }
            dir_entry++;

        }
        iteratorMutex.unlock();
        searchLine(workParameters,path);
    }
}


void Search_directory::searchLine(Work_parameters &workParameters, std::filesystem::path path) {
    int character=0,word =0, emptyLine=0,noEmptyLine=0;
    std::ifstream ifstream(path,std::ios::in);
    char c, prev;
    int endLineDistance;
    ifstream.get(prev);
    if(iswalpha(prev))character++;
    while(ifstream.get(c)){
        if(c==EOF){
            if(endLineDistance>0)noEmptyLine++;
            else emptyLine++;
            results.character+=character;
            results.noEmptyLineCount+=noEmptyLine;
            results.emptyLineCount+=emptyLine;
            results.word+=word;
        }
        if(!iswalpha(c)){
            if(iswalpha(prev)){
                word++;
            }
            if(!iswspace(c)){endLineDistance++;}
            else if(c=='\n'){
                if(endLineDistance>0)noEmptyLine++;
                else emptyLine++;
                endLineDistance=0;
            }
        }
        else{
            character++;
            endLineDistance++;
        }
        prev=c;
    }
}

Search_directory::Search_directory(const Work_parameters &workParameters):workParameters(workParameters) {

}



void Search_directory::show() {
    results.show();
}

void Search_directory::benchmark() {
    int max = std::thread::hardware_concurrency()<256?std::thread::hardware_concurrency():256;
    for(int i=1;i<=max;i*=2){
        results.zero();
        std::cout<<"Thread :"<<i<<std::endl;
        int start = clock();
        startSearch(i);
        int stop = clock();
        std::cout<<"Time to finish:"<<std::setprecision(3)<<((double )stop-start)/CLOCKS_PER_SEC<<std::endl<<std::endl;

    }

}





