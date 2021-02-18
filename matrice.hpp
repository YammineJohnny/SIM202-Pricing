//
//  matrice.hpp
//  SIM202
//
//  Created by Boubacar Sidibé on 04/02/2021.
//

#ifndef matrice_hpp
#define matrice_hpp

#include <stdio.h>

using namespace std;

class matrice{
    protected :
    int dim_l;
    int *p_inf;
    int *p_sup;
    vector< vector<double>> val;
    int pos(int i,int j) const{return j*dim_l+i;};//position de l'élément (i,j)
    public :
    matrice(int dim, int x=0);
    matrice(const matrice &);
    ~matrice();
};





#endif /* matrice_hpp */
