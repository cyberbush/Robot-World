const int HEIGHT = 40;
const int WIDTH = 40;

class world{
   private:
      int terrain[WIDTH][HEIGHT];
      robot *bots[WIDTH][HEIGHT];
   public:
      void set_up();
      void draw();
      void update();
};


void world::set_up(){
     for(int y = 0; y < HEIGHT; y++){
           for(int x = 0; x < WIDTH; x++){
                bots[x][y] = NULL;
                terrain[x][y] = rand()%1; // The number determines range, 1 will have 1 terrain types
            }
     }
     bots[3][3] = new robot(1);
     bots[37][37] = new robot(2);
     bots[3][35] = new robot(3);
     bots[35][3] = new robot(4);
}

void world::draw(){
    for(int y = 0; y < HEIGHT; y++){
          for(int x = 0; x < WIDTH; x++){
               if(bots[x][y] == NULL)
                     cout << (char)(terrain[x][y] + 46); // Terrain is going to be character number 46
               else
                     bots[x][y] -> printdirect();
          }
          cout << endl;
    }

    for(int y = 0; y < HEIGHT; y++)
          for(int x = 0; x < WIDTH; x++)
               if(bots[x][y] != NULL){
                     bots[x][y]->print();
                     bots[x][y]->refresh();	
                     cout << "\n";
               }

}

void world::update(){
    int tempx,tempy;
    robot *temp;
    for(int y = 0; y < HEIGHT; y++){
          for(int x = 0; x < WIDTH; x++){
               if(bots[x][y] != NULL){
                     tempx = x;
                     tempy = y;
                     bots[x][y] -> move(tempx,tempy);
                     if(tempx < 0 || tempx >= WIDTH)
                           tempx = x;
                     if(tempy < 0 || tempy >= HEIGHT)
                           tempy = y;
                     if(bots[tempx][tempy] == NULL){
                           temp = bots[x][y];
                           bots[x][y] = NULL;
                           bots[tempx][tempy] = temp;
                     }  
               }
          }
    }
}