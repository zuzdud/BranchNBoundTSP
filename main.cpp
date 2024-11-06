#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define INIT_FILE "DataInit.txt"

std::string method;
std::string outputFileName;
std::string outputFileExtention = ".csv";

std::vector<std::string> testFileNames;
std::vector<int> numberOfTestsList;

void readIniFile(const std::string &iniFileName) {
    std::ifstream iniFile(iniFileName);

    if (iniFile.is_open()) {
        std::string line;

        getline(iniFile, line);
        std::stringstream sstream(line);
        sstream >> method;

        while (getline(iniFile, line)) {
            std::string testFileName;
            std::stringstream sstream2(line);
            sstream2 >> testFileName;

            if(testFileName.find(outputFileExtention) != std::string::npos) {
                outputFileName = testFileName;
                break;
            }

            int numberOfTests;
            sstream2 >> numberOfTests;

            testFileNames.push_back(testFileName);
            numberOfTestsList.push_back(numberOfTests);

        }
    } else {
        std::cout << "Errror while trying to open ini file.";
    }
}

int main() {
    return 0;
}
