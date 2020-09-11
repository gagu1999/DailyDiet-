#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>
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
    Food(string name, int kcal, int carbo, int protein, int fat)
    {
      
      this -> name = new char[name.size() + 1];
      strcpy(this -> name, name.c_str()); 
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

    string getName()
    {
      return name;
    }

    int getKcal()
    {
      return kcal;
    }

    int getCarbo()
    {
      return carbohydrate;
    }

    int getProtein()
    {
      return protein;
    }

    int getFat()
    {
      return fat;
    }
};

void insertNewFood(vector<Food *> & vec); // 
void showDailyDietInfo(vector<Food *> & vec); // 하루동안 먹은 식단을 불러주는 함수.
void showMenu(); // 프로그램의 작동메뉴를 보여주는 함수.
void choseeFood(vector<Food *> & vec); // DB에서 음식을 고르는 함수.
#endif // FOOD_H