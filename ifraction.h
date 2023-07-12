#ifndef IFRACTION_H_INCLUDED
#define IFRACTION_H_INCLUDED
#include <string>

//void recover_data(string str);
class Fraction{

private:
    int numerateur , denominateur = 1, quotient = 0;
    int pgcd();
public:
    Fraction();
    Fraction(int num, int deno);
    Fraction(Fraction &fr);
    Fraction(double reel);
    Fraction(int quot, int num, int deno);
    void set_num_deno(int deno, int num);
    void set_num();
    void set_quot();
    int get_num();
    int get_deno();
    int rest();
    int get_quot();
    int num_reduit();
    int deno_reduit();
    Fraction operator+(Fraction const& f1) const;
    Fraction operator- (Fraction const& f1) const;
    Fraction operator* (Fraction const& f1) const;
    Fraction operator/ (Fraction const& f1) const;
    std::string result();

};



#endif // IFRACTION_H_INCLUDED
