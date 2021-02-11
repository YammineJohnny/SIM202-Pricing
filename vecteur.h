#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;


void stop(const char * msg);                     //message d'arret
void test_dim(int d1, int d2, const char * org); //test dimension

//classe vecteur de reels double precision
class vecteur
{
private :
  int dim_;          //dimension du vecteur
  double * val_;     //tableaux de valeurs

public:
  vecteur(int d=0, double v0=0); //dim et val constante
  vecteur(const vecteur & v);    //constructeur par copie
  ~vecteur();

  // operateur =
  vecteur & operator=(const vecteur &); //avec un vecteur
  vecteur & operator=(double x); //avec un reel
  
  //operateur []
  double & operator[](int i) const {return val_[i];};

  //operateur ()
  double & operator()(int i) const {return val_[i-1];};

  //operateur (i,j)
  //vecteur & operateur() (int i, int j);

  //operateur algebrique

    //scalaire
  vecteur & operator+=(double); //u+=x
  vecteur & operator-=(double); //u-=x
  vecteur & operator*=(double); //u*=x
  vecteur & operator/=(double); //u/=x
  
    //vecteur
  vecteur & operator+=(const vecteur &); //u+=v
  vecteur & operator-=(const vecteur &); //u-=v
  
  //bool
  bool operator==(const vecteur &); //egalite
  bool operator!=(const vecteur &);  //difference 

  //tools
  void init(int d);              //allocation
  void clear();                  //desallocation
  int dim() const {return dim_;} //acces dimension
};
// operateur + et -
vecteur operator+(const vecteur &);  //+u
vecteur operator-(const vecteur &); //-v
vecteur operator+(const vecteur &, double) ;//u+x
vecteur operator-(const vecteur &, double) ;//u-x
vecteur operator+(double , const vecteur &); //x+u
vecteur operator-(double , const vecteur &);//x-u
vecteur operator+(const vecteur &, const vecteur &); //u+v
vecteur operator-(const vecteur &, const vecteur &);//u-v

//operateur / et *
vecteur operator*(const vecteur &, double); //u*x
vecteur operator/(const vecteur &, double); //u/x
vecteur operator*(double , const vecteur &);  //x*u

// << et >> 
ostream & operator<<(ostream &, const vecteur &); // << 
istream & operator>>(istream &, const vecteur &); // >>

//produit scalaire |
double operator|(const vecteur &, const vecteur &); // |

//concatenation ,
vecteur operator,(const vecteur &, const vecteur &); // ,



#endif