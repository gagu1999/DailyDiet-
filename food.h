#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Food
{
  private:
    char * name; // 음식이름
    int kcal; //칼로리
    int carbohydrate; // 탄수화물
    int protein; // 단백질
    int fat; // 지방

  public:
    Food(char * name, int kcal, int carbo, int protein, int fat)
    {
      
      this -> name = new char[strlen(name) + 1];
      strcpy(this -> name, name); 
      this -> kcal = kcal; 
      this -> carbohydrate = carbo;
      this -> protein = protein; 
      this -> fat = fat;
    }
    
    void showInfo()
    {
      printf("음식이름: %s\n", name);
      printf("칼로리: %dkcal, 탄수화물: %dg, 단백질: %dg, 지방: %dg\n", kcal, carbohydrate, protein, fat);
    }
};

void insertNewFood(vector<Food *> & vec);
void showDailyDietInfo(vector<Food *> & vec);
void showMenu();
#endif // FOOD_H