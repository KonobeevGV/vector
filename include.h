#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#define N 30
#define V 3
using namespace std;
#define eps 1e-20
void autotest();
class CFabric;
class CPPVector0;
class CPPVector1; 
class CVector1
{
    friend class CPPVector0;  
    friend class CPPVector1; 
protected:
    vector<double> data; 
    int size; 
    std::string filename;    

    
public:
void get_size(){cout<<"size:"<<this->size<<endl;}
void str_set(string s){this->filename=s;}
void str_get(){cout<<"file name:"<<this->filename<<endl;}
bool isFileEmpty() const {std::ifstream file(filename);return file.peek() == std::ifstream::traits_type::eof();}
void clearFile() {
        if (!isFileEmpty()) { 
            std::remove(filename.c_str());
            std::cout << "File " << filename << " has been cleared." << std::endl;
        } else {
            std::cout << "File " << filename << " is already empty." << std::endl;
        }
    }
CVector1(const CVector1& other)
    {
        data.clear();
        this->size=other.size;
        for(int i=0;i<this->size;i++)
        {
            data.push_back(other.data[i]);
        }
    }
    CVector1() : size(V) {
        for(int i=0;i<this->size;i++)
        {
            data.push_back(0);
        }
    }
    CVector1(int n) : size(n) {
        filename = "ССССССССССP";
        for(int i=0;i<this->size;i++)
        {
            data.push_back(0);
        }
        
    }
    virtual ~CVector1() {
        cout<<"destrukt"<<endl;
    }
    int getSize() const {
        return size;
    }
    double& operator[](int index);
    virtual void printt()
    {
        cout<<"Я ЕБЛАН"<<endl;
    }
    double operator*(const CVector1& other);
    CVector1& operator=(const CVector1& other);
    CVector1& operator+(const CVector1& other);
    CVector1& operator-(const CVector1& other);
    static int Input(const char *name, vector <CVector1 *> &v,vector<CFabric *> &fabric);
};


class CPPVector0:public CVector1
{
    public:
    CPPVector0(const CPPVector0& other) : CVector1(other)
    {
        data.clear();
        this->size=other.size;
        for(int i=0;i<this->size;i++)
        {
            data.push_back(other.data[i]);
        }
    }
    CPPVector0() : CVector1() {}
    CPPVector0(int n) : CVector1(n) {
    }
    void printt()
    {
        std::ofstream outFile(this->filename,std::ofstream::app);
    if (outFile.is_open()) {
        outFile << "____"<<std::endl;
    for (int i = 0; i < size; ++i) {
        outFile << data[i] << std::endl;
            }
        outFile << "____" << std::endl;
        outFile.close();
    //std::cout << "Vector has been saved to file: " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
    }
};
    
class CPPVector1:public CVector1
{
    public:
    CPPVector1(const CPPVector1& other) : CVector1(other)
    {
        this->size=other.size;
        data.clear();
        for(int i=0;i<this->size;i++)
        {
            data.push_back(other.data[i]);
        }
    }
    CPPVector1() : CVector1() {}
    CPPVector1(int n) : CVector1(n) {
    }
    void printt() {

        std::ofstream outFile(this->filename,std::ofstream::app);
        if (outFile.is_open()) {
            outFile << "[ ";
        for (int i = 0; i < size; ++i) {
            outFile << data[i] << " ";
                }
            outFile << "]" << std::endl;
            outFile.close();
        //std::cout << "Vector has been saved to file: " << filename << std::endl;
        } else {
            std::cerr << "Unable to open file for writing: " << filename << std::endl;
        }
    }
};
class CFabric
{
	public:
	virtual CVector1 *Create() = 0;
	virtual ~CFabric() {}; 
};

class CFabric1 : public CFabric
{
	public:
	virtual CVector1 *Create(){return new CPPVector0;}  
};

class CFabric2 : public CFabric
{
	public:
	virtual CVector1 *Create(){return new CPPVector1;}         
};

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
