#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

std::vector<VectorXd> readFile(std::string file_name){

    std::vector<VectorXd> result;


    std::ifstream file(file_name);

    if(!file.is_open()) throw std::runtime_error("Could not open file");

    std::string line, colName;
    float val;

  
    int rowIdx = 0;

    while(std::getline(file, line))
    {
        std::stringstream ss(line);

        int colIdx = 0;
        while (ss >> val)
        {
            result.at(colIdx)(rowIdx) = val;
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }
        rowIdx++;
    }

    file.close();

    return result;


    
};


int main()
{
    /* code */
    std::vector<VectorXd> test = readFile("./data/processed_data.csv");

    std::cout << test.at(0) << std::endl;
    return 0;
}
