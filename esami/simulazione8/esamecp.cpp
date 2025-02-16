#include "esameh.h"
int main(){
    ofstream out;
    out.open("risultati.dat");
    posizione* p = new posizione [conta("posizioni.dat")];
    traiettoria* t = new traiettoria [conta("posizioni.dat")];
    cout << "il numero di posizioni è: " << conta("posizioni.dat") << endl;
    cout << "carico le posizioni" << endl;
    out << "il numero di posizioni è: " << conta("posizioni.dat") << endl;
    out << "carico le posizioni" << endl;
    load_pos(p,"posizioni.dat");
    cout << "stampo: " << endl;
    out << "stampo: " << endl;
    stampa_pos(p, "posizioni.dat", out);
    cout << "carico le traiettorie" << endl;
    out << "carico le traiettorie" << endl;
    load_traj(t,"traiettorie.dat");
    sort_traj(t,"traiettorie.dat");
    cout << "stampo: " << endl;
    out << "stampo: " << endl;
    stampa_traj(t, "traiettorie.dat", out);
    cout << "il drone seguendo la traiettoria è arrivato a : "  << follow(p[0],t[0]).x << " "<< follow(p[0],t[0]).y << endl;
    out << "il drone seguendo la traiettoria è arrivato a : "  << follow(p[0],t[0]).x << " "<< follow(p[0],t[0]).y << endl;
    cout << "la distanza massima è stata raggiunta seguendo la traiettoria: " << max_dist(p,t,"posizioni.dat", "traiettorie.dat", out).t << " " << max_dist(p,t,"posizioni.dat", "traiettorie.dat", out).T << endl;
    int cont = 0;
    for (int i = 0; i < conta("posizioni.dat"); i ++){
        for (int j = 0; j < conta("posizioni.dat"); j ++){
            if(collision(p[i],p[j], t[1], t[2]) == true ){
                cont ++;
            }
        }
    }
    cout << "ci sono state: " << cont << " collisioni " << endl;
    out << "ci sono state: " << cont << " collisioni " << endl;
    out.close();
    p = NULL;
    t = NULL;
    delete[] p;
    delete[] t;
}