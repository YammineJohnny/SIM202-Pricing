#include "vecteur.h" 

#include <cmath>
#include <cstdlib>
#include <iostream>

// fichier vecteur.cpp a completer

//utilitaire de messages d'erreur
void stop(const char * msg)
{
  cout<<"ERREUR classe vecteur, "<<msg;
  exit(-1);
}

void test_dim(int d1, int d2, const char * org)
{
  if(d1==d2)  return;
  cout<<org<<" ("<<d1<<","<<d2<<") dimensions incompatibles";
  exit(-1);
}

// constructeurs-destructeurs
vecteur::vecteur(int d, double v0) //dim et val constante
{
  init(d);
  for(int i=0;i<dim_;i++) val_[i]=v0;
}

vecteur::vecteur(const vecteur & v) //constructeur par copie
{
  init(v.dim_);
  for(int i=0;i<dim_;i++) val_[i]=v.val_[i]; //A changer apres!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

vecteur::~vecteur() {clear();}

// outils de construction et de destruction
void vecteur::init(int d) //initialisation avec allocation dynamique
{
  if(d<=0) stop("init() : dimension <=0");
  dim_=d;
  val_ = new double[d];
}

void vecteur::clear()    //desallocation
{
    if(val_!=0) delete [] val_;
    dim_=0;
}
//U=v
vecteur& vecteur::operator=(const vecteur & V){
  if(this==(&V)) return *this ; //meme vecteur
  if(dim_!=V.dim_){ //meme dimension
    if( val_!=0) delete [] val_;
    val_=new double [V.dim_];
  };
  dim_ =V.dim_;
  for(int i =0; i <dim_ ; i++) val_[i]=V. val_[i] ; //recopie
  return *this ;
}

//U=x
vecteur& vecteur::operator=(double x){
  for(int i =0; i <dim_ ; i++) val_[i]= x ; //copie de x
  return *this ;
}

//U(i,j)
//vecteur& vecteur::operator() (int i,int j){
  //if (j>i){stop("j>i");};
  //vecteur &W(j-i+1,0);
  //double *pw=&W(1);
  //for (int i=1;i<dim_;i++,p1++,pw++){
    //*pw=*p1;
  //};
//}

// u+x
vecteur& vecteur::operator+=(double x){
  double *pU=val_;
  for(int i =1; i <=dim_ ; i++,pU++) (*pU)+=x ;
  return *this ;
}

// u-x
vecteur& vecteur::operator-=(double x){
  double *pU=val_;
  for(int i =1; i <=dim_ ; i++,pU++) (*pU)-=x ;
  return *this;
}

// u*x
vecteur& vecteur::operator*=(double x){
  double *pU=val_;
  for(int i =1; i <=dim_ ; i++,pU++) (*pU)*=x ;
  return *this;
}


// u/x
vecteur& vecteur::operator/=(double x){ 
  if(x==0){ 
    stop("division nulle") ;
  }
  double *pU=val_;
  for(int i=1; i<=dim_ ; i++,pU++) (*pU)/=x ;
  return *this ;
}


//u+=v
vecteur& vecteur::operator+=(const vecteur & V){
  double *pU=val_;
  double *pV=V.val_;
  for(int i =1; i<=dim_ ; i ++,pU++,pV++) (*pU)+=(*pV) ;
  return *this;
}


//u-=v
vecteur& vecteur::operator-=(const vecteur & V){
  double *pU=val_;
  double *pV=V.val_;
  for(int i =1; i <= dim_ ; i ++,pU++,pV++) (*pU)-=(*pV) ;
  return *this ;
}

//+u
vecteur operator+(const vecteur & U){ 
  return U; 
}


//-u
vecteur operator-(const vecteur & U){
  vecteur V(U.dim(),0) ; 
  return V-=U; 
}

//u+x
vecteur operator+(const vecteur &U, double x){
  vecteur V(U) ; 
  return V+=x ; 
}

//u-x
vecteur operator-(const vecteur &U, double x){
  vecteur V(U) ; 
  return V-=x ; 
}




// x+u
vecteur operator+(double x , const vecteur &U){ 
  return U+x ; 
}


// x-u
vecteur operator - (double x , const vecteur &U){
  vecteur V(U.dim(),x); 
  return V-=U; 
}

//u+v
vecteur operator+(const vecteur &U, const vecteur &W){
  vecteur V(U) ; 
  return V+=W; 
}

//u-v
vecteur operator-(const vecteur &U, const vecteur &W){
  vecteur V(U); 
  return V-=W; 
}


//u*x
vecteur operator*(const vecteur &U, double x ){
  vecteur V(U); 
  return V*=x; 
}

// u/x
vecteur operator/(const vecteur &U, double x){
  vecteur V(U); 
  return V/=x; 
}


// x*u
vecteur operator*(double x,const vecteur &U){ 
  return U*x; 
}




// u==v
bool vecteur::operator==(const vecteur &V){ 
  if( dim_ !=V.dim_ ) return false;
  double *pU=val_;
  double *pV=V.val_;
  for(int i =1;i<=dim_;i++,pU++,pV++){
    if((*pU) != (*pV)) return false;
  }
  return true ;
}

//u!=v
bool vecteur::operator!=(const vecteur &V){
  if (dim_ != V.dim_) return true; 
  return !((*this)==V); 
}

// <<
ostream & operator<<(ostream &os , const vecteur &U){
  double *pU=&U(1);
  os<<"(";
  for(int i=1;i<=U.dim(); i++,pU++){
    os<<(*pU)<<" ";
  };
  os<<")"<<endl;
  return os;
}

// <<
istream & operator>>(istream &is , vecteur &U){ 
  double *pU=&U(1);
  for(int i =1; i<=U.dim() ; i++,pU++){
    is>>(*pU);
  }
  return is;
}

//produit scalaire
double operator|(const vecteur & U , const vecteur & V){
  if(U.dim()!=V.dim()){
    stop("Vecteur de dimension differentes");
  };
  double p=0;
  double *p1=&U(1) ;
  double *p2=&V(1) ;
  
  for(int i=1; i<=U.dim(); i++,p1++,p2++){
    p +=(*p1)*(*p2);
  };
  return p ;
}

//concatenation
vecteur operator,(const vecteur & U, const vecteur & V){
  vecteur W(U.dim()+V.dim()-1,0);
  double *p1=&U(1);
  double *p2=&V(1);
  double *pw=&W(1);
  for (int i=1;i<U.dim();i++,p1++,pw++){
    *pw=*p1;
  };

  for (int j=U.dim();j<U.dim()+V.dim();j++,p2++,pw++){
    *pw=*p2;
  };
  return W;
}

