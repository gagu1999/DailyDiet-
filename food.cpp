#include <iostream>
#include <vector>
#include "food.h"
using namespace std;

void insertNewFood(vector<Food *> & vec)
{
  char name[31];
  int kcal, carbo, protein, fat;
  cout << "음식 이름을 입력해주세요(30글자 내외로 ㅎ):\n";
  cin >> name;
  cout << "칼로리는 어떻게 되나요? (kcal) \n";
  cin >> kcal;
  cout << "탄수화물은 얼마나 포함되어 있지요? (g)\n";
  cin >> carbo;
  cout << "단백질 함량은 얼마에요? (g)\n";
  cin >> protein;
  cout << "지방함량은?? (g)\n";
  cin >> fat;
  Food * food = new Food(name, kcal, carbo, protein, fat);
  vec.push_back(food);
}

void showDailyDietInfo(vector<Food *> & vec)
{
  for(int i = 0; i < vec.size(); i++)
  {
    printf("%d번째로 먹은 음식입니다.\n", i+1);
    vec[i] -> showInfo();
    cout <<'\n';
  }
}

void showMenu()
{
  vector<Food*> container;
  while(1)
  {
    int n;
    cout << "원하는 동작의 번호를 입력해주세요\n";
    cout << "1. 먹은 음식 입력하기: \n";
    cout << "2. 하루동안 먹은 음식 출력하기\n";
    cout << "3. 프로그램 종료\n";
    cout << "번호를 입력해주세요: \n";
    cout << "------------------------------------------------------------\n";
    cin >> n;
    if(n == 3)
    {

    }
    switch(n)
    {
      case 1:
      {
        cout << "------------------------------------------------------------\n";
        cout << "오늘 먹은 음식을 추가합니다.\n";
        insertNewFood(container);
        cout << "------------------------------------------------------------\n";
        break;
      }
      case 2:
      {
        cout << "------------------------------------------------------------\n";
        cout << "오늘 하루동안 먹은 모든 음식을 출력합니다.\n";
        showDailyDietInfo(container);
        cout << "------------------------------------------------------------\n";
        break;
      }
      default:
      {
        cout << "------------------------------------------------------------\n";
        cout << "프로그램을 종료합니다.\n";
        return;
      }
    }
  }
}