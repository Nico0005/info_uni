#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
struct posizione {
int x,y; //coordinate intere iniziali di un drone
};

struct traiettoria {
int t; //lunghezza della traiettoria
char* T; //array di t comandi di movimento
};

int conta (const char*);
void swap(int*, int*);
void load_pos(posizione*, const char*);
void stampa_pos(posizione*, const char*, ofstream&);
void load_traj(traiettoria*, const char*);
void sort_traj(traiettoria*, const char*);
void stampa_traj(traiettoria*, const char*, ofstream&);
posizione follow( posizione start, traiettoria C );
traiettoria max_dist(posizione*, traiettoria*, const char*, const char*, ofstream&);
void move(posizione , traiettoria );
bool collision(posizione p, posizione q, traiettoria Cp, traiettoria Cq);

