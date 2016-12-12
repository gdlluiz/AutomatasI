#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
int generador;
int actual;
int siguiente;
}prod;

typedef vector<prod> gramatica;
typedef set<int> setear;
typedef map<int, setear> fila;
typedef map<int, fila> tabla;

bool cyk(gramatica &g, string &str){
    tabla tab;
    int n=str.size();
    for(int i = 1; i <= n; i++){
        for(gramatica::iterator it = g.begin(); it < g.end(); it++){
            if(*str.substr(i-1,1).c_str() == it->actual){
                tab[i][1].insert(it -> generador);
            }
        }
    }

    for(int j = 2; j <= n; j++){
        for(int i = 1; i <= (n-j+1); i++){
            for(int k = 1; k <= (n-1); k++){
                for(gramatica::iterator it = g.begin(); it < g.end(); it++){
                    if((tab[i][k].find(it -> actual) != tab[i][k].end()) &&
                            (tab[i+k][j-k].find(it -> siguiente) != tab[i+k][j-k].end())){
                        tab[i][j].insert(it -> generador);
                    }
                }
            }
        }
    }
   return ((tab[1][n].find(g.begin() -> generador))!= tab[1][n].end());
}

int main()
{
    gramatica G;
    string str;
    //gramatica equivalente

    prod a = {'Q', 'E', 'D1'};
    prod b = {'D1', 'Cq', 'D2'};
    prod c = {'D2', 'Q', 'D3'};
    prod d = {'D3', 'Ce', 'Q'};
    prod e = {'Q', 'E', 'D4'};
    prod f = {'D4', 'Cm', 'T'};
    prod g = {'Q', 'E', 'D5'};
    prod h = {'D5', 'Cd', 'T'};
    prod i = {'Q', 'T', 'D6'};
    prod j = {'D6', 'Cp', 'F'};
    prod k = {'Q', 'T', 'D7'};
    prod l = {'D7', 'Cs', 'F'};
    prod m = {'Q', 'Cl', 'D8'};
    prod n = {'D8', 'Q', 'Cr'};
    prod o = {'Q', 'Cd', 'F'};
    prod p = {'Q', 'n'};
    prod q = {'E', 'E', 'D9'};
    prod r = {'D9', 'Cm', 'T'};
    prod s = {'E', 'E', 'D10'};
    prod t = {'D10', 'Cd', 'T'};
    prod u = {'E', 'T', 'D11'};
    prod v = {'D11', 'Cp', 'F'};
    prod w = {'E', 'T', 'D12'};
    prod x = {'D12', 'Cs', 'F'};
    prod y = {'E', 'Cl', 'D13'};
    prod z = {'D13', 'Q', 'Cr'};
    prod aa = {'E', 'Cd', 'F'};
    prod ab = {'E', 'n'};
    prod ac = {'T', 'T', 'D14'};
    prod ad = {'D14', 'Cp', 'F'};
    prod ae = {'T', 'T', 'D15'};
    prod af = {'D15', 'Cs', 'F'};
    prod ag = {'T', 'Cl', 'D16'};
    prod ah = {'D16', 'Q', 'Cr'};
    prod ai = {'T', 'Cd', 'F'};
    prod aj = {'T', 'n'};
    prod ak = {'F', 'Cl', 'D17'};
    prod al = {'D17', 'Q', 'Cr'};
    prod am = {'F', 'Cd', 'F'};
    prod an = {'F', 'n'};
    prod ao = {'Cq', 'q'};
    prod ap = {'Ce', 'e'};
    prod aq = {'Cm', 'm'};
    prod ar = {'Cd', 'd'};
    prod as = {'Cp', 'p'};
    prod au = {'Cs', 's'};
    prod av = {'Cl', 'l'};
    prod aw = {'Cr', 'r'};


    G.push_back(a);
    G.push_back(b);
    G.push_back(c);
    G.push_back(d);
    G.push_back(e);
    G.push_back(f);
    G.push_back(g);
    G.push_back(h);
    G.push_back(i);
    G.push_back(j);
    G.push_back(k);
    G.push_back(l);
    G.push_back(m);
    G.push_back(n);
    G.push_back(o);
    G.push_back(p);
    G.push_back(q);
    G.push_back(r);
    G.push_back(s);
    G.push_back(t);
    G.push_back(u);
    G.push_back(v);
    G.push_back(w);
    G.push_back(x);
    G.push_back(y);
    G.push_back(z);
    G.push_back(aa);
    G.push_back(ab);
    G.push_back(ac);
    G.push_back(ad);
    G.push_back(ae);
    G.push_back(af);
    G.push_back(ag);
    G.push_back(ah);
    G.push_back(ai);
    G.push_back(aj);
    G.push_back(ak);
    G.push_back(al);
    G.push_back(am);
    G.push_back(an);
    G.push_back(ao);
    G.push_back(ap);
    G.push_back(aq);
    G.push_back(ar);
    G.push_back(as);
    G.push_back(au);
    G.push_back(av);
    G.push_back(aw);

    cout << "Cadena: ";
    cin >> str;

    if(cyk(G, str)) {
        std::cout << "cadena aceptada" << std::endl;
    }else{
        std::cout << "rechazada" << std::endl;
    }
    return 0;
}
