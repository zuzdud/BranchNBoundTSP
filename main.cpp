#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

#define INIT_FILE "DataInit.txt"

std::string method;
std::string outputFileName;
std::string outputFileExtention = ".csv";

std::vector<std::string> testFileNames;
std::vector<int> numberOfTestsList;

std::vector<int> numberOfVerticesList;
std::vector<int> optDistances;
std::vector<std::string> optRoutes;

std::vector<std::vector<int> > adjacencyMatrix;

void printVector(std::vector<int> vector);

void readIniFile(const std::string &iniFileName) {
    if (std::ifstream iniFile(iniFileName); iniFile.is_open()) {
        std::string line;

        getline(iniFile, line);
        std::stringstream sstream(line);
        sstream >> method;

        while (getline(iniFile, line)) {
            std::string testFileName;
            std::stringstream sstream2(line);
            sstream2 >> testFileName;

            if (testFileName.find(outputFileExtention) != std::string::npos) {
                outputFileName = testFileName;
                break;
            }

            int numberOfTests;
            sstream2 >> numberOfTests;

            testFileNames.push_back(testFileName);
            numberOfTestsList.push_back(numberOfTests);
        }
        std::cout << "Ini file read successfully." << std::endl;
    } else {
        std::cout << "Errror while opening ini file." << std::endl;
    }
}

void readTestFile(const std::string &testFileName) {
    if (std::fstream testFile(testFileName); testFile.is_open()) {
        std::string line;
        int numberOfVertices;
        int optDistnace;
        std::string optRoute;

        getline(testFile, line);
        std::stringstream sstream(line);
        sstream >> numberOfVertices >> optDistnace;
        getline(sstream, optRoute);
        numberOfVerticesList.push_back(numberOfVertices);
        optDistances.push_back(optDistnace);
        optRoutes.push_back(optRoute);

        while (getline(testFile, line)) {
            std::stringstream sstream2(line);
            std::vector<int> row;
            int temp;

            for (int i = 0; i < numberOfVertices; i++) {
                sstream2 >> temp;
                row.push_back(temp);
            }
            adjacencyMatrix.push_back(row);
        }
        std::cout << "Test file " << testFileName << " read successfully" << std::endl;
    }else {
        std::cout << "Error opening test file: " << testFileName << std::endl;
    }
}

void printVector(std::vector<int> vector) {
    std::ostringstream oss;
    std::copy(vector.begin(), vector.end(), std::ostream_iterator<int>(oss, " "));
    std::cout << oss.str() << std::endl;
}

int main() {
    readIniFile(INIT_FILE);
    readTestFile("tsp_6_1.txt");
    return 0;
}
