#include "esameh.h"

int conta (const char* f){
    int dim = 1;
    ifstream in (f);
    string s;
    getline(in,s);
    if (in.fail()){
        return -1;
    }
    while (!in.eof()){
        getline(in,s);
        dim ++;
    }
    return dim;
}

void swap(int* a, int* b){
    int* t = a;
    a = b;
    b = t;
}

void load_pos(posizione* p, const char* f){
    ifstream in(f);
    for (int i = 0; i < conta(f); i++){
        in >> p[i].x >> p[i].y;
    }   
}

void stampa_pos(posizione* p, const char* f, ofstream& out){
    cout << "le posizioni sono: " << endl;
    out << "le posizioni sono: " << endl;
    for (int i = 0; i < conta(f); i ++){
        cout << p[i].x << ' ' << p[i].y << endl;
        out << p[i].x << ' ' << p[i].y << endl;
    }
}

void load_traj(traiettoria* t, const char* f){
    ifstream in(f);
    for (int i = 0; i < conta(f); i++){
        in >> t[i].t;
        t[i].T = new char [t[i].t];
        for (int j = 0; j < t[i].t; j ++){
            in >> t[i].T[j];
        }
    }

}

void sort_traj(traiettoria* t, const char* f){
    for (int i = 0; i < conta(f); i ++){
        for (int j = 0; j < conta(f); j ++){
            if(t[i].t > t[j].t){
                swap(t[i].t, t[j].t);
                swap (t[i].T, t[j].T);
            }
        }
    }
}

void stampa_traj(traiettoria* t, const char* f, ofstream& out){
    cout << "le traiettorie sono: "  <<  conta(f) << endl;
    out << "le traiettorie sono: " << conta(f) << endl;
    for (int i = 0; i < conta(f); i ++){
        cout << t[i].t << " ";
        out << t[i].t << " ";
        for (int j = 0; j < t[i].t; j ++){
            cout << " " << t[i].T[j];
            out << " " << t[i].T[j];
        }
        cout << endl;
        out << endl;
    }
}

posizione follow( posizione start, traiettoria C ){
    posizione p = start;

    for (int i = 0; i < C.t; i ++){
        if (C.T[i] == 'N'){
            p.y += 1;
        }
        if (C.T[i] == 'S'){
            p.y -= 1;
        }
        if (C.T[i] == 'E'){
            p.x += 1;
        }
        if (C.T[i] == 'O'){
            p.x -= 1;
        }
    }
    return p;
}

traiettoria max_dist(posizione* p, traiettoria* t, const char* po, const char* tr, ofstream& out){
    int max = 0;
    traiettoria traj;
    for (int i = 0; i < conta(po); i ++){
        for (int j = 0; j < conta (tr); j ++){
            if (sqrt(abs(pow(follow(p[i], t[j]).x,2) + pow(follow(p[i], t[j]).y,2))) > max){
                max = sqrt(pow(follow(p[i], t[j]).x,2) + pow(follow(p[i], t[j]).y,2));
                traj = t[j];
            }
        }
    }
    out << "la distanza massima è stata raggiunta seguendo la traiettoria: " << traj.t << " " << traj.T << endl;
    return traj;
}

void move(posizione p, traiettoria t, int n){
    if (t.T[n] == 'N'){
        p.y += 1;
    }
    if (t.T[n] == 'S'){
        p.y -= 1;
    }
    if (t.T[n] == 'E'){
        p.x += 1;
    }
    if (t.T[n] == 'O'){
        p.x -= 1;
    }
}

bool collision(posizione p, posizione q, traiettoria Cp, traiettoria Cq){
    int maxt = (Cp.t > Cq.t ? Cp.t:Cq.t);
    for (int i = 0; i < maxt; i ++){
        if (p.y == q.y && p.x == q.x){
            return true;
        }
        else {
            move(p,Cp,i);
            move(q,Cq,i);
        }
    }
    return false;
}