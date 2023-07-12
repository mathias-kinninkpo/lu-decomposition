#include "matrix.h"
#include "ifraction.h"
#include <iomanip>
#include <cmath>

Matrix::Matrix(int M,int N,string c_name,int c_type)
{
    rows=M;cols=N;
    name=c_name;
    type=c_type;

    mat=new double*[rows];
    for(int i=0;i<rows;i=i+1)
        mat[i]=new double[cols];
}

Matrix::~Matrix()
{
    for(int i=0;i<rows;i=i+1)
    {
        delete[]mat[i];
    }
    delete []mat;
}

void Matrix::draw()
{
    if(type==as_matrix)
    {
        cout<<"====================================== L'affichage de la Matrice  "<<name<<"  ============================================="<<endl;

        for(int i=0;i<rows;i=i+1)
        {
            for(int j=0;j<cols;j=j+1)
            {
                if(mat[i][j]<10E-13&&mat[i][j]>-10E-13)
                    mat[i][j]=0;
                Fraction f(round(mat[i][j] * 10E3 ) / 10E3);
                if (f.deno_reduit() == 1)
                    cout<<setprecision(3)<<setw(11)<<right<<mat[i][j] << "(" << f.num_reduit() << ")  ";
                else
                    cout<<setprecision(3)<<setw(11)<<right<<mat[i][j] << "(" << f.num_reduit() << "/" << f.deno_reduit() << ")  ";
                // cout << setw(11) << f.num_reduit() << "/" << f.deno_reduit() ; 
            }

            cout<<setw(0)<<endl;
        }
        cout<<endl;
    }

    else if(type==as_vector)
    {
        cout<<"====================================== l'affichage du Vecteur "  <<name<<"  ================================ "<<endl;

        for(int i=0;i<rows;i=i+1)
        {
            if(mat[i][0]<10E-13&&mat[i][0]>-10E-13)
                mat[i][0]=0;

            cout<<setprecision(3)<<setw(11)<<left<<mat[i][0];
        }
        cout<<setw(0)<<endl<<endl<<endl<<endl;
    }
}

void Matrix::readMatrix()
{
    // if(b<a){double c=b;b=a;a=c;}
    // double width=b-a;

    for(int i=0;i<rows;i=i+1)
    for(int j=0;j<cols;j=j+1)
        std::cin >> mat[i][j] ;
        
}
