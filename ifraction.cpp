#include <iostream>
// #include <string>
#include "ifraction.h"



void Fraction::set_num_deno(int deno,int num){
    if(deno==0){
       denominateur = 1;
       numerateur = num;
    }
    else if(deno<0){
        denominateur = -1*deno;
        numerateur = -1*num;
    }else{
       denominateur = deno;
       numerateur = num;
    }
}

Fraction::Fraction(Fraction &f){
    this->denominateur = f.get_deno();
    this->numerateur = f.get_num();
    this->quotient = f.quotient;
}

Fraction::Fraction(double a)
{
    numerateur = a*1000;
    denominateur = 1000;
}

Fraction::Fraction(int num, int deno){

    set_num_deno(deno, num);
}
Fraction::Fraction( int quot, int num, int deno){
    // the order of this instructions is very important
    quotient += quot;
    set_num_deno(deno, num);
}
Fraction::Fraction(){}
int Fraction::get_num(){
    return numerateur;
}

int Fraction::get_deno(){
    return denominateur;
}
int Fraction::pgcd(){
    int num = get_num();
    int deno = get_deno();
    if(num<0){
        num = -1*num;
    }
    int tmp;
    while(deno != 0){
            tmp = deno;
            deno = num % deno;
            num = tmp;
    }
    return num;

}
int Fraction::num_reduit(){
    return numerateur/pgcd();
}

int Fraction::deno_reduit(){
    return denominateur/pgcd();
}

int Fraction::get_quot(){
    return num_reduit()/deno_reduit() + quotient;
}
int Fraction::rest(){
    return num_reduit()%deno_reduit();
}
Fraction Fraction::operator+(Fraction const& f1) const{

    Fraction res(this->quotient + f1.quotient, this->numerateur * f1.denominateur + this->denominateur * f1.numerateur , this->denominateur * f1.denominateur);
    return res;

}
Fraction Fraction::operator- (Fraction const& f1) const{

    Fraction res(this->quotient - f1.quotient, this->numerateur * f1.denominateur - this->denominateur * f1.numerateur, this->numerateur * f1.numerateur );
    return res;

}
Fraction Fraction::operator* (Fraction const& f1) const{

    Fraction res( this->quotient * f1.quotient, this->numerateur * f1.numerateur, this->denominateur * f1.denominateur);
    return res;

}
Fraction Fraction::operator/ (Fraction const& f1) const{

    Fraction res(this->quotient * f1.quotient, this->numerateur * f1.denominateur, this->denominateur * f1.numerateur);
    return res;

}
std::string Fraction::result(){
    std::string s = "";
   if(get_quot() < 0 && rest() > 0){
       s+= std::to_string(get_quot())+ " - " + std::to_string(rest()) + "/" + std::to_string(deno_reduit()) ;
   }else if(get_quot() < 0 && rest() < 0){
       s+= std::to_string(get_quot()) + " - " + std::to_string(-1*rest()) + "/" + std::to_string(deno_reduit());
    }else if (get_quot() == 0){
        s+= std::to_string(rest()) + "/" + std::to_string(deno_reduit());
    }else if (rest() == 0){
        s+= std::to_string(get_quot());
    }else{
        s+=std::to_string(get_quot()) + " + " + std::to_string(rest()) + "/" + std::to_string(deno_reduit());
    }
    return s;
}


