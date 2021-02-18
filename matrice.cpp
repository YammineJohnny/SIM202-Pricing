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


using namespace std;

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


matrice :: matrice(int dim, int x){
    dim_l = dim;
    p_sup = new int[dim_l];
    p_sup = new int[dim_l];
}



            


