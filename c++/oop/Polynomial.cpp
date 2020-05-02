#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Polynomial
{
private:
    int giaTriMu;
    vector<double> heSo;
public:
    Polynomial();
    void set(int);
    Polynomial operator+(Polynomial dt1);
    Polynomial operator-(Polynomial dt1);
    Polynomial operator*(Polynomial dt1);
    
	Polynomial &operator=(Polynomial dt);
    Polynomial &operator+=(Polynomial dt);
    Polynomial &operator-=(Polynomial dt);
    Polynomial &operator*=(Polynomial dt);
    
	friend ostream &operator<<(ostream &out, Polynomial dt);
    ~Polynomial();
};
void Polynomial::set(int k){
    int input;
    giaTriMu = k;
    for (int i = 0; i < k + 1; i++)
    {
        cout << "nhap he so cua mu " << i << "\n";
        cin >> input;
        heSo.push_back(input);
    }
}
Polynomial Polynomial::operator+(Polynomial dt1){
    Polynomial kq;
    int i, j;
    i = heSo.size();
    j = dt1.heSo.size();
    if (i > j)
    {
        kq.giaTriMu = i - 1;
        for (int k = 0; k < j; k++)
        {
            kq.heSo.push_back(heSo[k] + dt1.heSo[k]);
        }
        for (int k = j; k < i; k++)
        {
            kq.heSo.push_back(heSo[k]);
        }
    }
    else
    {
        kq.giaTriMu = j - 1;
        for (int k = 0; k < i; k++)
        {
            kq.heSo.push_back(heSo[k] + dt1.heSo[k]);
        }
        for (int k = i; k < j; k++)
        {
            kq.heSo.push_back(dt1.heSo[k]);
        }
    }
    return kq;
}
Polynomial Polynomial::operator-(Polynomial dt){
    Polynomial kq;
    int i, j;
    i = heSo.size();
    j = dt.heSo.size();
    if (i > j)
    {
        kq.giaTriMu = i - 1;
        for (int k = 0; k < j; k++)
        {
            kq.heSo.push_back(heSo[k] - dt.heSo[k]);
        }
        for (int k = j; k < i; k++)
        {
            kq.heSo.push_back(heSo[k]);
        }
    }
    else
    {
        kq.giaTriMu = j - 1;
        for (int k = 0; k < i; k++)
        {
            kq.heSo.push_back(heSo[k] - dt.heSo[k]);
        }
        for (int k = i; k < j; k++)
        {
            kq.heSo.push_back(-dt.heSo[k]);
        }
    }
    return kq;
}
Polynomial Polynomial::operator*(Polynomial dt){
    Polynomial kq;
    int i, j;
    i = heSo.size();
    j = dt.heSo.size();
    vector<double> temp(i + j - 1, 0);
    kq.heSo = temp;
    kq.giaTriMu = i + j - 2;
    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < j; l++)
        {
            temp[k + l] = (heSo[k] * dt.heSo[l]);
        }
        for (int i = 0; i < temp.size(); i++)
        {
            kq.heSo[i] = kq.heSo[i] + temp[i];
            temp[i] = 0;
        }
    }
    return kq;
}
Polynomial &Polynomial::operator=(Polynomial dt){
    this->giaTriMu = dt.giaTriMu;
    for (int i = 0; i < int(dt.heSo.size()); i++)
    {
        this->heSo.push_back(dt.heSo[i]);
    }
    return *this;
}
Polynomial &Polynomial::operator+=(Polynomial dt){
    int m, n;
    m = heSo.size();
    n = dt.heSo.size();
    if (m < n)
    {
        giaTriMu = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (m > i)
                heSo[i] = heSo[i] + dt.heSo[i];
            else
            {
                heSo.push_back(dt.heSo[i]);
            }
        }
    }
    else
    {
        giaTriMu = m - 1;
        for (int i = 0; i < n; i++)
        {
            heSo[i] = heSo[i] + dt.heSo[i];
        }
    }
    return *this;
}
Polynomial &Polynomial::operator-=(Polynomial dt){
    int m, n;
    m = heSo.size();
    n = dt.heSo.size();
    if (m < n)
    {
        giaTriMu = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (m > i)
                heSo[i] = heSo[i] - dt.heSo[i];
            else
            {
                heSo.push_back(-dt.heSo[i]);
            }
        }
    }
    else
    {
        giaTriMu = m - 1;
        for (int i = 0; i < n; i++)
        {

            heSo[i] = heSo[i] - dt.heSo[i];
        }
    }
    return *this;
}
Polynomial &Polynomial::operator*=(Polynomial dt){
    Polynomial kq;
    int i, j;
    i = heSo.size();
    j = dt.heSo.size();
    vector<double> temp(i + j - 1, 0);
    kq.heSo = temp;
    kq.giaTriMu = i + j - 2;
    for (int k = 0; k < i; k++)
    {
        for (int l = 0; l < j; l++)
        {
            temp[k + l] = (heSo[k] * dt.heSo[l]);
        }
        for (int i = 0; i < temp.size(); i++)
        {
            kq.heSo[i] = kq.heSo[i] + temp[i];
            temp[i] = 0;
        }
    }
    for (int i = heSo.size(); i < kq.heSo.size(); i++)
    {
        heSo.push_back(kq.heSo[i]);
    }
    giaTriMu = kq.giaTriMu;
    return *this;
}
ostream &operator<<(ostream &out, Polynomial dt){
    for (int i = 0; i < int(dt.heSo.size()); i++)
    {
        if (i == int(dt.heSo.size() - 1))
        {
            out << dt.heSo[i] << "x^" << i;
        }
        else
        {
            if (i == 0)
            {
                if (dt.heSo[i] != 0)
                {
                    out << dt.heSo[i] << " + ";
                }
            }
            else
            {
                if (dt.heSo[i] != 0)
                {
                    out << dt.heSo[i] << "x^" << i << " + ";
                }
            }
        }
    }
    return out;
}
Polynomial::Polynomial(/* args */){
}
Polynomial::~Polynomial(){
}
int main()
{
    Polynomial a, b, c;
    int n,m;
    cout<<"nhap so mu cua da thuc 1:";
    cin>>n;
    cout<<"nhap so mu cua da thuc 2:";
    cin>>m;
    a.set(n);
    b.set(4);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    c = a + b;
    cout << "a+b : " << c << endl;
    c = a - b;
    cout << "a-b : " << c << endl;
    c = a * b;
    cout << "a*b : " << c << endl;
    a *= b;
    cout << "a*=b : " << a << endl;
    a+=b;
    cout << "a+=b : " << c << endl;
    a-=b;
    cout << "a-=b : " << c << endl;
    return 0;
}
