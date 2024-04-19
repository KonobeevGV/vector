#include "include.h"
//////////////////father
CVector1& CVector1::operator+(const CVector1& vector) {
	
//		double Sum[len];

		for (int i = 0; i < size; i++) {
		
			this->data[i] += vector.data[i];
		}

//		CVector Sum_vector(Sum);
	
		return *this;
	}

CVector1& CVector1::operator-(const CVector1& vector) {

//		double Sub[len];

		for (int i = 0; i < size; i++) {

			this->data[i] -= vector.data[i];
	        }
	
//                CVector Sub_vector(Sub);

		return *this;
	}

double CVector1::operator*(const CVector1& other)
{
    double x=0;
    if (size != other.size) {
        std::cerr << "Cannot add vectors of different sizes!" << std::endl;
        exit(1); // Программа завершает работу из-за ошибки
    }

    for (int i = 0; i < size; ++i) {
        //std::cout<<"(+)"<<data[i]<<"+"<<other.data[i];
        x+= data[i] * other.data[i];
    }
    return x;
}

CVector1& CVector1::operator=(const CVector1& other) {
if (this != &other) {

    data.clear();
    size = other.size;


    for (int i = 0; i < size; ++i) {
        data.push_back(other.data[i]);
    }
}
return *this;
}

double& CVector1::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Index out of range!" << std::endl;
        exit(1);
    }
    return data[index];
}

int CVector1::Input(const char *name, vector <CVector1 *> &v,vector<CFabric *> &fabric)
{
	ifstream f(name); string str;
	while (getline(f, str))
	{
		stringstream ss(str); istream_iterator<string> it;
		it = ss;
		if (it != istream_iterator<string>())
		{
			if (fabs(stod(*it) - 0) < eps)
			{
				CVector1 *w = fabric[0] -> Create(); size_t i; ++it; 
                w->str_set(*it);
                ++it;
				//cout << "\n|" << *it << "|\n"; ++it;
				for (i = 0; i < N && it != istream_iterator<string>(); ++it) (*w)[i++] = stod(*it);
				v.push_back(w);
			}
			if (fabs(stod(*it) - 1) < eps)
			{
				CVector1 *w = fabric[1] -> Create(); size_t i; ++it; 
                w->str_set(*it);
                ++it;
				//cout << "\n|" << *it << "|\n"; ++it;
				for (i = 0; i < N && it != istream_iterator<string>(); ++it) (*w)[i++] = stod(*it);
				v.push_back(w);
			}
		}
	}
	return 0;	         

}
