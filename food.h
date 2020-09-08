#ifndef FOOD_H
#define FOOD_H

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
      this -> name = name; 
      this -> kcal = kcal; 
      this -> carbohydrate = carbo;
      this -> protein = protein; 
      this -> fat = fat;
    }
    
    void showInfo()
    {
      printf("음식이름 : %s\n", name);
      printf("칼로리 : %d, 탄수화물 : %d, 단백질 : %d, 지방 : %d\n", kcal, carbohydrate, protein, fat);
    }
};

#endif FOOD_H
