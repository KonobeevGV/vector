#include "include.h"
void createFiles() {
    for (int i = 1; i <= 10; ++i) {
        std::string filename = "out" + std::to_string(i) + ".txt";
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "This is file " << filename << std::endl;
            outFile.close();
            std::cout << "File " << filename << " has been created." << std::endl;
        } else {
            std::cerr << "Unable to create file " << filename << std::endl;
        }
    }
}


//генерация файла input:
void generateInput(int T) {
    std::ofstream outFile("input.txt");
    if (!outFile.is_open()) {
        std::cerr << "Unable to open input.txt for writing." << std::endl;
        return;
    }
    T++;
    T--;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Запись случайных данных в файл
    for (int i = 0; i < N; ++i) {
        // Генерация случайного числа 0 или 1
        int randomBit = rand() % 2;

        // Генерация случайного числа от 1 до 10 для имени файла
        int randomIndex = rand() % 10 + 1;

        // Генерация случайных чисел double
        int count = V; // Количество чисел
        outFile << randomBit << " out" << randomIndex << ".txt ";
        for (int j = 0; j < count; ++j) {
            outFile << static_cast<double>(rand()) / RAND_MAX * 100.0 << " "; // Генерация чисел от 0 до 100
        }
        outFile << std::endl;
    }

    outFile.close();
    std::cout << "Input data has been generated and written to input.txt." << std::endl;
}


//
///////////////////////////

////////////////////////////


int main() {
    string filename="out";
    string name;
    vector<CVector1 *> v; 
    vector<CFabric *> fabric;
    fabric.push_back(new CFabric1);
    fabric.push_back(new CFabric2);
    generateInput(N);
    //очистка всех файлов
    for(int i=1;i<11;i++)
    {
        std::string j= std::to_string(i);
        name=filename+j+".txt";
        cout<<"FILE "<<name<<" clear..."<<endl;
        std::remove(name.c_str());
    }
	CVector1::Input("input.txt", v,fabric);
    cout<<v.size()<<endl;
    CVector1 sum(V),dif(V);

    for (size_t i = 0; i < v.size(); ++i) v[i]->printt();
    /*for (size_t i = 0; i < v.size()-1; ++i)
    {
        for(int j;j<V;j++)
        {

        }
    }*/
    
    
    
    
    
    
    
    
    
    
    
    for (size_t i = 0; i < fabric.size(); ++i) delete fabric[i];
    
    
    
    
    
    for (size_t i = 0; i < v.size(); ++i) delete v[i];




    //vector<CVector> data;
    //vector<CVector1> data1;
   /*
    int count_for_vec=0;
    int count_for_vec1=0;
    CPPVector0 q(V);
    generateInput(N);
    string filename="out";
    string name;
    string name_for_read[7];
    //char trash;
    //char randomV;
    очистка всех файлов
    for(int i=1;i<11;i++)
    {
        std::string j= std::to_string(i);
        name=filename+j+".txt";
        cout<<"FILE "<<name<<" clear..."<<endl;
        std::remove(name.c_str());
    }
    std::vector<CVector1> mass_of_fathers;
    std::vector<CPPVector0> mass_of_vecs;
    std::vector<CPPVector1> mass_of_vecs1;
    std::vector<int> VtupeVec;
    std::vector<std::string> file_nameVec;
    std::vector<double*> dataVec;

    readDataFromFile("input.txt", VtupeVec, file_nameVec, dataVec);

    // Проверка считанных данных
    for (size_t i = 0; i < VtupeVec.size(); ++i) {
        std::cout << "Data " << i + 1 << ":" << std::endl;
        std::cout << "Vtupe: " << VtupeVec[i] << std::endl;
        std::cout << "file_name: " << file_nameVec[i] << std::endl;
        double* data = dataVec[i];
        if (data) {
            std::cout << "data: ";
            //int Vtupe = VtupeVec[i];
            for (int j = 0; j < V; ++j)      {
                std::cout << data[j] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No data read." << std::endl;
        }
    }
    for (size_t i = 0; i < VtupeVec.size(); ++i)
    {
        std::cout << "file_name: " << file_nameVec[i] << std::endl;
    }
    cout<<endl<<endl;
    for (int i ;i<N;i++)
    {
        if(VtupeVec[i]==0)
        {
            CPPVector0 ccv(V);
            ccv.str_set(file_nameVec[i]);
            cout<<endl<<"ccv "<<i<<endl;
            for(int j=0;j<V;j++)
            {
            ccv[j] = dataVec[i][j];
            }
            mass_of_fathers.push_back(ccv);
            
        }
        else
        {
            CPPVector1 ccv1(V);
            ccv1.str_set(file_nameVec[i]);
            cout<<endl<<"ccv1 "<<i<<endl;
            for(int j=0;j<V;j++)
            {
            ccv1[j] = dataVec[i][j];
            }
            
            mass_of_fathers.push_back(ccv1);
        }
    }
    for(int i=0;i<mass_of_fathers.size();++i)
    {
        mass_of_fathers[i].str_get();
        cout<<endl;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<mass_of_vecs.size()<<" "<<mass_of_vecs1.size()<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl<<"mass_of_vecs1[1].str_get();"<<"   ";
    for(int i=0;i<mass_of_vecs1.size();i++)
    {
       cout<<endl<<"mass_of_vecs1["<<i<<"].str_get();"<<"   "; 
       mass_of_vecs1[i].str_get(); 
       cout<<endl;
    }
    for(int i=0;i<mass_of_vecs.size();i++)
    {
       cout<<endl<<"mass_of_vecs["<<i<<"].str_get();"<<"   "; 
       mass_of_vecs[i].str_get(); 
       cout<<endl;
    }
    for(int i;i<mass_of_fathers.size();i++)
    {
        
        mass_of_fathers[i].printt();
    }


    autotest();
















    / Освобождение памяти, выделенной под массивы данных
    for (size_t i =0;i < mass_of_vecs.size();i++)
    {
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        mass_of_vecs[i].str_get();
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    for (size_t i =0 ; i < mass_of_vecs1.size() ; i++)
    {
        mass_of_vecs1[i].str_get();
    }
    
    for (size_t i = 0; i < dataVec.size(); ++i) {
       delete[] dataVec[i];
     }

    int Vtupe;
    std::string file_name;
    double* data = nullptr;

    readDataFromFile("input.txt", Vtupe, file_name, data);

    // Проверка считанных данных
    std::cout << "Vtupe: " << Vtupe << std::endl;
    std::cout << "file_name: " << file_name << std::endl;
    if (data) {
        if(Vtupe==0)
        {
        std::cout << "data: ";
        for (int i = 0; i < V; ++i) {
             Cv[i]=data[i];
        }
        
        Cv.str_set(file_name);
        Cv.print();
        }
        else
        {
            std::cout << "data: ";
        for (int i = 0; i < V; ++i) {
             Cv1[i]=data[i];
        }
        std::cout << std::endl;
        Cv1.str_set(file_name);
        Cv1.print();
        } 
    } else {
        std::cout << "No data read." << std::endl;
    }


    // Освобождение памяти, выделенной под массив data
    delete[] data;
    
       

    
    //
    CVector1 vec11(N);
    CVector1 vec21(N);
    CVector1 sum1(N);
    CVector1 minus1(N);
    CVector vec1(N);
    CVector vec2(N);
    CVector sum(N);
    CVector minus(N);
    double prod1;
    double prod;
    srand( time( 0 ) );
    for (int i = 0; i < vec11.getSize(); ++i) {
        vec11[i] = double(rand()%100)/10;
        vec1[i]=vec11[i];
        vec21[i] = double(rand()%100)/10; 
        vec2[i]=vec21[i];
    }
    fout<<"Vector1 1:"<<std::endl;
    vec11.print(fout);
    fout<<"Vector1 2:"<<std::endl;
    vec21.print(fout);
    sum1=vec11+vec21;
    minus1=vec11-vec21;
    prod1=vec11*vec21;
    fout<<"Vector1 1 + Vector1 2:"<<std::endl;
    sum1.print(fout);
    fout<<"Vector1 1 - Vector1 2:"<<std::endl;
    minus1.print(fout);
    fout<<"Vector1 1 * Vector1 2: "<<std::endl<<"{"<<prod1<<"}"<<std::endl;


    fout<<"Vector 1:"<<std::endl;
    vec1.print();
    fout<<"Vector 2:"<<std::endl;
    vec2.print();
    sum=vec1+vec2;
    minus=vec1-vec2;
    prod=vec1*vec2;
    fout<<"Vector 1 + Vector 2:"<<std::endl;
    sum.print();
    fout<<"Vector 1 - Vector 2:"<<std::endl;
    minus.print();
    fout<<"Vector 1 * Vector 2: "<<std::endl<<"{"<<prod<<"}"<<std::endl;*/
    autotest();
    return 0;
}
