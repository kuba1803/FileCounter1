#include <iostream>
#include "DataContainers/FinalResults.h"
#include "DataContainers/Work_parameters.h"
#include "Search_directory.h"

int main(int argc, char *argv[]) {
    Work_parameters workParameters;

    for(int argi=1;argi<argc;argi++) {
        if (argv[argi][1] == 'p') {
            argi++;
            if (argi < argc && argv[argi][0] != '-') {
                workParameters.setPath(argv[argi]);
            } else {
                std::cout << "Incorrect paremeters -p";
            }

        } else if (argv[argi][1] == 't') {
            argi++;
            if (argi < argc && argv[argi][0] != '-') {
                try {
                    int param = std::stoi(argv[argi]);
                    if (param < 0)throw new std::invalid_argument("");
                    workParameters.setThread(param);
                }
                catch (std::invalid_argument e) {
                    std::cout << "Incorrect paremeters -t";
                    return 0;
                }
            } else {
                std::cout << "Incorrect paremeters -t";
            }
        } else if (argv[argi][1] == 'b') {
            workParameters.setBenchmarks(true);
        }
    }
    Search_directory searchDirectory(workParameters);
    try {
        if(workParameters.isBenchmarks()){
            searchDirectory.benchmark();
        } else {
            searchDirectory.startSearch();
        }
    }
    catch (std::filesystem::filesystem_error e)
    {
        std::cout<<"Invaid path"<<std::endl;
        return 0;
    }
    searchDirectory.show();
    return 0;
}
