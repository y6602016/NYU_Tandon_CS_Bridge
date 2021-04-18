#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;


const int GRID_SIZE = 20;
const int INITIALIZE_ANT = 100;
const int INITIALIZE_BUG = 5;
const int DOODLEBUG = 1;
const int ANT = 2;
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;
const int DOODLE_STARVE = 3;
const char ANT_CHAR = 'O';
const char BUG_CHAR = 'X';

class Organism;
class Doodlebug;
class Ant;

class Grid{
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    Grid();
    ~Grid();

    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Display();
    void oneStep();

private:
    Organism* grid[GRID_SIZE][GRID_SIZE];
};

class Organism{
    friend class Grid;
public:
    Organism();
    Organism(Grid *grid, int x, int y);
    virtual ~Organism();

    virtual void breed() = 0;
    virtual void move() = 0;
    virtual int getType() = 0;
    virtual bool starve() = 0;
protected:
    int x, y;
    bool moved;
    int breedCounts;
    Grid *grid;

};

class Ant: public Organism{
    friend class Grid;

public:
    Ant();
    Ant(Grid *grid, int x, int y);

    void breed();
    void move();
    int getType();
    bool starve(){ return false; }
};

class Doodlebug : public Organism{
    friend class Garden;
public:
    Doodlebug();
    Doodlebug(Grid *garden, int x, int y);
    void breed();
    void move();
    int getType();
    bool starve();
private:
    int starveCount;
};



// =================== Grid ==================

Grid::Grid(){
    int i, j;
    for (i=0; i < GRID_SIZE; i++){
        for (j=0; j < GRID_SIZE; j++){
            grid[i][j] = NULL;
        }
    }
}

Grid::~Grid(){
    int i, j;
    for (i = 0; i < GRID_SIZE; i++){
        for(j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] != NULL)
                delete (grid[i][j]);
        }
    }
}

Organism* Grid::getAt(int x, int y){
    if((x >= 0) && (x < GRID_SIZE) && (y >= 0) && (y < GRID_SIZE)){
        return grid[x][y];
    }
    return NULL;
}

void Grid::setAt(int x, int y, Organism *org){
    if((x >= 0) && (x < GRID_SIZE) && (y >= 0) && (y < GRID_SIZE)){
        grid[x][y] = org;
    }
}

void Grid::Display(){
    cout << endl << endl;
    for(int j=0; j < GRID_SIZE; j++){
        for(int i=0; i < GRID_SIZE; i++){
            if(grid[i][j] == NULL){
                cout << ".";
            }else if(grid[i][j]->getType() == ANT){
                cout << ANT_CHAR;
            }else{
                cout << BUG_CHAR;
            }
        }
        cout << endl;
    }
}

void Grid::oneStep(){
    // if occupied, not move
    for (int i=0; i < GRID_SIZE; i++){
        for(int j=0; j < GRID_SIZE; j++){
            if (grid[i][j] !=  NULL) {
                grid[i][j]->moved = false;
            }
        }
    }

    // if not yet moved, then move;
    for(int i=0; i < GRID_SIZE; i++){
        for(int j=0; j < GRID_SIZE; j++){
            if((grid[i][j] != NULL) && (grid[i][j]->moved == false)){
                grid[i][j]->moved = true;
                grid[i][j]->move();
            }
        }
    }

    // if it's an bug and the starve is true, then die
    for(int i=0; i < GRID_SIZE; i++){
        for(int j=0; j < GRID_SIZE; j++){
            if((grid[i][j] != NULL) && (grid[i][j]->getType() == DOODLEBUG)){
                if (grid[i][j]->starve()){
                    delete (grid[i][j]);
                    grid[i][j] = NULL;
                }
            }
        }
    }

    // if moved, check whether it can breed
    for(int i=0; i < GRID_SIZE; i++){
        for(int j=0; j < GRID_SIZE; j++){
            if((grid[i][j] != NULL) && (grid[i][j]->moved == true)){
                grid[i][j]->breed();
            }
        }
    }
}
// =================== Grid ==================


// =================== Organism ==================
Organism::Organism(){
    grid = NULL;
    moved = false;
    breedCounts = 0;
    x = 0;
    y = 0;
}

Organism::Organism(Grid *grid, int x, int y){
    this->grid = grid;
    moved = false;
    this->x = x;
    this->y = y;
    grid->setAt(x, y, this);
}

Organism::~Organism(){}
// =================== Organism ==================



// =================== Ant ==================
Ant::Ant() : Organism() {}
Ant::Ant(Grid *grid, int x, int y): Organism(grid, x, y) {}
void Ant::move(){
    int direction = rand() % 4;

    if(direction == 0){ // move down
        if((y > 0) && (grid->getAt(x, y - 1) == NULL)){
            grid->setAt(x, y - 1, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            y--;
        }
    }else if (direction == 1){ // move up
        if((y < GRID_SIZE - 1) && (grid->getAt(x, y + 1) == NULL)){
            grid->setAt(x, y + 1, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            y++;
        }
    }else if(direction == 2){ // move left
        if ((x > 0) && (grid->getAt(x - 1, y) == NULL)){
            grid->setAt(x - 1, y, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            x--;
        }
    }else{ //move right
        if((x < GRID_SIZE - 1) && (grid->getAt(x + 1, y) == NULL)){
            grid->setAt(x + 1, y, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            x++;
        }
    }
}

int Ant::getType() {return ANT;}
void Ant::breed(){
    breedCounts++;
    if(breedCounts == ANT_BREED){
        breedCounts = 0;
        if((y>0) && (grid->getAt(x, y - 1) == NULL)){
            Ant *newAnt = new Ant(grid, x, y - 1);
        }else if ((y < GRID_SIZE - 1) && (grid->getAt(x, y + 1) == NULL)){
            Ant *newAnt = new Ant(grid, x, y + 1);
        }else if((x>0) && (grid->getAt(x - 1, y) == NULL)){
            Ant *newAnt = new Ant(grid, x - 1, y);
        }else if((x < GRID_SIZE - 1) && (grid->getAt(x + 1, y) == NULL)){
            Ant *newAnt = new Ant(grid, x + 1, y);
        }
        // if all areas are occupied, then not breed and reset the count to 0
        else {
            breedCounts = 0;
        }
    }
}
// =================== Ant ==================


// =================== Doodlebug ==================

Doodlebug::Doodlebug(): Organism() { starveCount = 0; }
Doodlebug::Doodlebug(Grid *garden, int x, int y): Organism(garden, x, y) { starveCount = 0; }

void Doodlebug::move(){
    if((y>0) && (grid->getAt(x, y - 1) != NULL) && (grid->getAt(x, y - 1)->getType() == ANT)){
        delete (grid->grid[x][y - 1]);
        grid->grid[x][y - 1] = this;
        grid->setAt(x, y, NULL);
        starveCount = 0;
        y--;
        return;
    }else if((y < GRID_SIZE - 1) && (grid->getAt(x, y + 1) != NULL) && (grid->getAt(x, y + 1)->getType() == ANT)){
        delete (grid->grid[x][y + 1]);
        grid->grid[x][y + 1] = this;
        grid->setAt(x, y, NULL);
        starveCount = 0;
        y++;
        return;
    }else if((x>0) && (grid->getAt(x - 1, y) != NULL) && (grid->getAt(x - 1, y)->getType() == ANT)){
        delete (grid->grid[x - 1][y]);
        grid->grid[x - 1][y] = this;
        grid->setAt(x, y, NULL);
        starveCount = 0;
        x--;
        return;
    }else if((x < GRID_SIZE - 1) && (grid->getAt(x + 1, y) != NULL) && (grid->getAt(x + 1, y)->getType() == ANT )){
        delete (grid->grid[x + 1][y]);
        grid->grid[x + 1][y] = this;
        grid->setAt(x, y, NULL);
        starveCount = 0;
        x++;
        return;
    }

    int direction = rand() % 4;

    if(direction == 0){
        if((y>0) && (grid->getAt(x, y - 1) == NULL)){
            grid->setAt(x, y - 1, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            y--;
        }
    }else if(direction == 1){
        if((y < GRID_SIZE - 1) && (grid->getAt(x, y + 1) == NULL)){
            grid->setAt(x, y + 1, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            y++;
        }
    }else if(direction == 2){
        if((x>0) && (grid->getAt(x - 1, y) == NULL)){
            grid->setAt(x - 1, y, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            x--;
        }
    }else{
        if((x < GRID_SIZE - 1) && (grid->getAt(x + 1, y) == NULL)){
            grid->setAt(x + 1, y, grid->getAt(x, y));
            grid->setAt(x, y, NULL);
            x++;
        }
    }
    starveCount++;
}

int Doodlebug::getType() { return DOODLEBUG; }

void Doodlebug::breed(){
    breedCounts++;
    if(breedCounts == DOODLE_BREED){
        breedCounts = 0;
        if((y>0) && (grid->getAt(x, y - 1) == NULL)){
            Doodlebug * newDoodle = new Doodlebug(grid, x, y - 1);
        }else if ((y < GRID_SIZE - 1) && (grid->getAt(x, y + 1) == NULL)){
            Doodlebug *newDoodle = new Doodlebug(grid, x, y + 1);
        }else if((x>0) && (grid->getAt(x - 1, y) == NULL)){
            Doodlebug *newDoodle = new Doodlebug(grid, x - 1, y);
        }else{
            Doodlebug *newDoodle = new Doodlebug(grid, x + 1, y);
        }
    }
}

bool Doodlebug::starve(){
    return (starveCount > DOODLE_STARVE) ? true : false;
}
// =================== Doodlebug ==================

int main() {
    string s;
    srand(time(NULL));
    Grid g;

    int antCount = 0;
    int doodleCount = 0;

    while(antCount < INITIALIZE_ANT){
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if(g.getAt(x, y) == NULL){
            antCount++;
            Ant *a1 = new Ant(&g, x, y);
        }
    }

    while(doodleCount < INITIALIZE_BUG){
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if(g.getAt(x, y) == NULL){
            doodleCount++;
            Doodlebug *d1 = new Doodlebug(&g, x, y);
        }
    }

    //run program
    while (true){
        g.Display();
        g.oneStep();
        cout << endl << "Press enter for next step" << endl;
        getline(cin, s);
    }

    return 0;
}