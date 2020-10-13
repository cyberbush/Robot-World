/* David Bush, CS 120-02, Assigment 11, Complete, 4/17/20 */
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#include"robot.h"
#include"world.h"

     int main(){
         world a_world;
         srand(time(NULL));
        a_world.set_up();
        do{
            a_world.update();
            a_world.draw();
            cin.ignore();
        }while(1);
        return 0;
    }