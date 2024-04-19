#include "include.h"
void readDataFromFile(const std::string& filename, std::vector<int>& VtupeVec, std::vector<std::string>& file_nameVec, std::vector<std::vector <double> >& dataVec) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);

        int Vtupe;
        std::string file_name;
        std::vector<double> tempData;
        double value;

        // Считываем целое число
        if (!(iss >> Vtupe)) {
            std::cerr << "Failed to read integer from file." << std::endl;
            continue;
        }

        // Считываем строку
        if (!(iss >> file_name)) {
            std::cerr << "Failed to read string from file." << std::endl;
            continue;
        }

        // Считываем массив даблов
        while (iss >> value) {
            tempData.push_back(value);
        }

        // Сохраняем данные в векторах
        VtupeVec.push_back(Vtupe);
        file_nameVec.push_back(file_name);
        dataVec.push_back(tempData);
    }

    inFile.close();
}
void autotest()
{
    int maincount=0;
    double scch=0;
    double sc;
    int count=0;
    std::vector<CPPVector0> mass_of_fathers;
    std::vector<int> VtupeVec;
    std::vector<std::string> file_nameVec;
    std::vector<std::vector <double> > dataVec;
    readDataFromFile("input.txt", VtupeVec, file_nameVec, dataVec);
    for(int i=0;i<N;i++)
    {
        CPPVector0 c(V);

        for(int j=0;j<V;j++){
        c[j]=dataVec[i][j];
        }
        mass_of_fathers.push_back(c);
    }
    for(int j=0;j<N-1;j++)
    {   
        CVector1 tmp1=mass_of_fathers[j];
        CVector1 tmp2=mass_of_fathers[j+1];
        CVector1 sum=mass_of_fathers[j]+mass_of_fathers[j+1];
    for(int i=0;i<V;i++)
    {
        cout<<sum[i]<<"   ????   "<<tmp1[i]<<"+"<<tmp2[i]<<endl;
        if(fabs(sum[i]-mass_of_fathers[j][i])<eps)
        {
            count++;
            maincount++;
        }
    }
    }
    if (count==V*(N-1))
    {
        cout<<endl<<V*(N-1)<<" TESTs + PASSED"<<endl;
    }
    else
    {
        cout<<"NOOOOOOOOOOOOOOOO(((((((("<<endl;
    }
    count=0;
    for(int j=0;j<N-1;j++)
    {
         CVector1 tmp1=mass_of_fathers[j];
         CVector1 tmp2=mass_of_fathers[j+1];
         CVector1 dif=mass_of_fathers[j]-mass_of_fathers[j+1];
    for(int i=0;i<V;i++)
    {
        cout<<dif[i]<<"   ????   "<<tmp1[i]<<"-"<<tmp2[i]<<endl;
        if(fabs(dif[i]-mass_of_fathers[j][i])<eps)
        {
            count++;
            maincount++;
        }
    }
    }
    if (count==V*(N-1))
    {
        cout<<endl<<V*(N-1)<<" TESTs - PASSED"<<endl;
    }
    else
    {
        cout<<"NOOOOOOOOOOOOOOOO(((((((("<<endl;
    }
    count=0;
    for(int j=0;j<N-1;j++)
    {
        sc=mass_of_fathers[j]*mass_of_fathers[j+1];
        cout<<sc<<"   ????   ";
        for(int k=0;k<V;k++)
        cout<<mass_of_fathers[j][k]<<" ";
        cout<<"* ";
        for(int l=0;l<V;l++)
        cout<<mass_of_fathers[j+1][l]<<" ";
        cout<<endl;
        for(int k=0;k<V;k++)
        {
            scch+=mass_of_fathers[j][k]*mass_of_fathers[j+1][k];
        }
    
    if(fabs(sc-scch)<eps)
        {
            count++;
            maincount++;
        }
    scch=0;
    }
    if (count==N-1)
    {
        cout<<endl<<V*(N-1)<<" TESTs * PASSED"<<endl;
    }
    else
    {
        cout<<"NOOOOOOOOOOOOOOOO(((((((("<<endl;
    }
    cout<<maincount<<" tests out of "<<V*(N-1)*2+(N-1)<<" passed!!!"<<endl;
}
