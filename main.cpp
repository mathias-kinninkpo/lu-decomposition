#include "matrix.h"
#include "lu.h"
#include <iostream>
#include <fstream>
#include <string>

// solve system of linear equations Ax=b
// LU matrix decomposition: A=LU
// L - lower triangular matrix L and U - upper triangular matrix
// solve system of equations LUx=b
// first forward substitution Ly=b
// then backward substitution Ux=y
// author: Wojciech Mormul
// date: 14.11.2015

using namespace std;



int main()

{

    string ch;
    std::fstream file;
    file.open("Texte.txt.txt",ios::in);
    if(file.is_open()){
        while(std::getline(file,ch)){
            cout << ch << endl;
        }
        std::cout << "\t\t\t\t\t\t\t\t\t\t SUR NOTRE APPLICATION DE RESOLUTION DE SYSTEME LINEAIRE!\n" << std::endl;
    }else{
        std::cout << "Bienvenue Sur notre application de resolution de système linéaire!\n" << std::endl;
    }
            
    // cout<<endl<<"=================== LU matrix decomposition ===================="<<endl<<endl;

    srand(time(0));
    int N = 4;
    cout << "\n\n\n\n1. LECTURE DES MATRICES A ET B'\n\n\n";
    std::cout << "Veuillez entrer d'abord la taille de la matrice associée de (S) :";
    cin >> N;
    Matrix A(N,N,"A",Matrix::as_matrix);
    std::cout << "VEUILLEZ ENTRER LA MATRICE A DU SYTEME (vous pouvez copier et coller)!\n" << std::endl;
    A.readMatrix();
    std::cout << "VEUILLEZ ENTRER LA MATRICE B DU SYTEME (vous pouvez copier et coller)! :" << N << "elements" << std::endl;
    Matrix b(N,1,"B",Matrix::as_vector);
    b.readMatrix();

    LU_decomp lu_decomp(N);
    lu_decomp.find_decomposition(A);
    lu_decomp.forward_substitution(b);
    lu_decomp.backward_substitution();
    cout << "\n\n\n2. L'AFFICHAGE DES MATRICES A ET B'\n\n\n";
    A.draw();
    b.draw();
    cout << "\n\n\n\3. L'AFFICHAGE DES MATRICES L ET U'\n\n\n";
    lu_decomp.L->draw();
    lu_decomp.U->draw();
    cout << "\n\n\n4. Le verteur X la solution de l'equation\n\n\n";
    lu_decomp.x->draw();

    return 0;
}
