#include "teamvec.h"
#include <stdlib.h>

struct teamvec {
    Team **teams;  
    int size;      
    int capacity;  
};

TeamVec *tv_create(void) {
    TeamVec *tv = (TeamVec *)malloc(sizeof(struct teamvec));
    if (tv != NULL) {
        tv->capacity = 4; // Vetor inicial pequeno[cite: 9]
        tv->size = 0;
        tv->teams = (Team **)malloc(tv->capacity * sizeof(Team *));
    }
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if (tv->size == tv->capacity) {
        tv->capacity *= 2;
        tv->teams = (Team **)realloc(tv->teams, tv->capacity * sizeof(Team *));
    }
    
    tv->teams[tv->size] = t;
    tv->size++;
}

int tv_size(TeamVec *tv) {
    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {
    if (i >= 0 && i < tv->size) {
        return tv->teams[i];
    }
    return NULL;
}

void tv_free(TeamVec *tv) {
    if (tv != NULL) {
        for (int i = 0; i < tv->size; i++) {
            team_free(tv->teams[i]);
        }
        free(tv->teams);
        free(tv);
    }
}