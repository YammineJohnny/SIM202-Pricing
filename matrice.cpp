//
//  matrice.cpp
//  SIM202
//
//  Created by Boubacar Sidibé on 04/02/2021.
//

#include "matrice.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>


void test_taille(int d1, int d2, const char * org)
{
  if(d1==d2)  return;
    std::cout<<org<<" ("<<d1<<","<<d2<<") tailles incompatibles";
  exit(-1);
}

matrice :: ~matrice(){
    delete [] p_inf;
    delete [] p_sup;
};


matrice :: matrice(int dl,int nb_val, double x){
    dim_l = dl;
    l_val = nb_val;
    val = new double[l_val];
    p_inf = new int[dl];
    p_sup = new int[dl];
    for(int i =0;i<l_val;i++){
        val[i] = x;
    };
};

matrice :: matrice(const matrice & M){
    matrice(M.dim_l, M.l_val);
    for(int i =0;i<l_val;i++){
        val[i] = M.val[i];
    };
};



            


