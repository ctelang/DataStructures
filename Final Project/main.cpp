#include "hash.hpp"
#include "LL.hpp"
#include <fstream>
#include <vector>
#include <chrono>

const vector<string> split(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

int main(int argc, char** argv)
{
    // TODO: Need to repeat tests with dataSetB
    int testDataA[40000];
    float insert[400];
    float search[400];

    string dataSetAFilename = argv[1];
    ifstream dataAFile(dataSetAFilename);
    string dataS;

    getline(dataAFile, dataS); // dataS now holds the entire contents of dataSetA.csv

    vector<string> stringVector = split(dataS, ',');
    vector<int> intVector;

    for(int i = 0; i < 100; i++)
    {
        intVector.push_back(stoi(stringVector.at(i)));
    }
    // intVector now hold the first 100 integers in datasetA.csv

    LinkedList ll;
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++)
    {
        ll.insert(intVector[i]);
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> execTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\nAverage time to insert item in LL: " << execTime.count() / 100.0 << " seconds." <<  std::endl << std::endl;

}