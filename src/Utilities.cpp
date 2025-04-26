#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>
#include <typeinfo>
#include <csignal>

using Eigen::MatrixXd;
using Eigen::VectorXd;


int count_rows(const std::string& file_name) {
    std::ifstream file(file_name);
    std::string line;
    int row_count = 0;
    while (getline(file, line)) {
        ++row_count;
    }
    return row_count;
};


std::vector<VectorXd> readFile(std::string file_name, bool hasHeader = true){

    std::vector<VectorXd> result;


    std::ifstream file(file_name);
    
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line, colName;
    float val;
    float val_;
    int fileLine = 0;
    int num_rows = count_rows(file_name);
    VectorXd target(num_rows);

    int rowIdx = 0;

    while(std::getline(file, line))
    {
        std::stringstream ss1(line);
        std::stringstream ss(line);
        int colLength = 0;
        while (ss1 >> val_)
        {
            if(ss1.peek() == ',') ss1.ignore();
            colLength++;
        };

        if (hasHeader && fileLine==0){
            fileLine++;
            continue;
        }
        if(colLength <= 1){
            std::cout << "Omittig line: " << fileLine << std::endl;
            continue;
        };
        
        
        int colIdx = 0;
        VectorXd col(colLength-1);

        if (fileLine == 2274) {
            raise(SIGTRAP); // Trigger a breakpoint for the debugger
        }

        while (ss >> val) {   
            if (colIdx < colLength - 1) {
                col(colIdx) = val;
                if (ss.peek() == ',') ss.ignore();
                colIdx++;
            } else {
                // Check if the last value is an integer
                if (std::floor(val) != val) {
                    //std::cout << "Skipping line " << fileLine << " due to non-integer target value: " << val << std::endl;
                    fileLine++;
                    continue; // Skip this line
                }
                target(fileLine) = val; // Add the last value to the target vector
            }
        }
        
        if(!hasHeader || fileLine > 0){
            rowIdx++;
            result.push_back(col);
        }
        fileLine++;
    }
    result.push_back(target);
    file.close();

    return result;


    
};


int main()
{
    /* code */
    std::vector<VectorXd> test = readFile("/Users/marcusandersson/Desktop/neural_network/data/processed_data.csv", true); // Set to 'false' if no header

    std::cout << test.back() << std::endl;
    return 0;
}

