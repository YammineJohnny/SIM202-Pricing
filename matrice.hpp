//
//  matrice.hpp
//  SIM202
//
//  Created by Boubacar Sidibé on 04/02/2021.
//

#ifndef matrice_hpp
#define matrice_hpp

#include <stdio.h>

class matrice{
    protected :
    int dim_l, l_val;
    int *p_inf;
    int *p_sup;
    double *val;
    int pos(int i,int j) const{return j*dim_l+i;};//position de l'élément (i,j)
    //double *adresse(int i, int j);   // adresse de l'élément (i,j)
    public :
    matrice();
    matrice(int dl,int dc, double x = 0);
    matrice(const matrice &);
    ~matrice();
    void print();
};





#endif /* matrice_hpp */
