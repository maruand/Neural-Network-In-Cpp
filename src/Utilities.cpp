#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

std::vector<VectorXd> readFile(std::string file_name, bool hasHeader = true){

    std::vector<VectorXd> result;


    std::ifstream file(file_name);
    
    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line, colName;
    float val;
    float val_;
    int fileLine = 0;

  
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
        }
        

        int colIdx = 0;
        VectorXd col(colLength);
        while (ss >> val)
        {
            col(colIdx) = val;
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }

        if(!hasHeader || fileLine > 0){
            rowIdx++;
            result.push_back(col);
        }
        fileLine++;
    }

    file.close();

    return result;


    
};


int main()
{
    /* code */
    std::vector<VectorXd> test = readFile("/Users/marcusandersson/Desktop/neural_network/data/processed_data.csv", true); // Set to 'false' if no header

    std::cout << test.at(0) << std::endl;
    return 0;
}

