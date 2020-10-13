void robot::turnLeft(){
   energy--;
   direction = (direction + 3) % 4; // a left is 3 rights
}
void robot::turnRight(){
   energy--;
   direction = (direction + 1) % 4;
}
void robot::forward(int &x,int &y){
   if(direction == 0)
       y--;    
   if(direction == 2)
       y++;    
   if(direction == 1)
       x++;    
   if(direction == 3)
       x--;    
}
void robot::move(int &x,int &y){
    if(moved == 1)
        return;
    switch(rand()%4){
        case 0:
             turnLeft();
             break;
        case 1:
             turnRight();
             break;
        case 2:
        case 3: 
             forward(x,y);
             break;
        default: 
             cout << "Error in robot move." << endl;
    }
    moved = 1;
}
void robot::print(){
    cout << "Robot " << ID << ": Energy = "  << energy << " Direction = " << direction;
}
void robot::draw(){
    cout << "#";
}