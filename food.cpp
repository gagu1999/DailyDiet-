#include <iostream>
#include <vector>
#include "food.h"
using namespace std;

void insertNewFood(vector<Food *> & vec)
{
  char name[31];
  int kcal, carbo, protein, fat;
  ofstream writeFile;
  writeFile.open("dataBase.txt", ios::app);
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
  writeFile.write((food->getName().c_str()), food->getName().size());
  writeFile.write("\n", 1);
  string str;
  str = to_string(kcal);
  str += "\n";
  writeFile.write(str.c_str(), str.size());
  str = to_string(carbo);
  str += "\n";
  writeFile.write(str.c_str(), str.size());
  str = to_string(protein);
  str += "\n";
  writeFile.write(str.c_str(), str.size());
  str = to_string(fat);
  str += "\n";
  writeFile.write(str.c_str(), str.size());
  writeFile.close();
}

void showDailyDietInfo(vector<Food *> & vec)
{
  int kcal, carbo, protein, fat;
  for(int i = 0; i < vec.size(); i++)
  {
    printf("%d번째로 먹은 음식입니다.\n", i+1);
    vec[i] -> showInfo();
    kcal += vec[i] -> getKcal();
    carbo += vec[i] -> getCarbo();
    protein += vec[i] -> getProtein();
    fat += vec[i] -> getFat();
    cout <<'\n';
  }
  printf("오늘 하루동안 먹은 총 영양소입니다.\n");
  printf("칼로리:%d kcal, 탄수화물:%d g, 단백질:%d g, 지방:%d g\n", kcal, carbo, protein, fat);
}

void choseeFood(vector<Food *> & vec)
{
  int idx = 1;
  ifstream readFile;
  readFile.open("dataBase.txt");
  if(readFile.is_open())
  {
    while(!readFile.eof())
    {
      string str;
      getline(readFile, str);
      cout << idx << "번 음식: " << str <<"\n";
      idx++;
      getline(readFile, str);
      getline(readFile, str);
      getline(readFile, str);
      getline(readFile, str);
    }
  }
  readFile.close();
  cout << "음식번호를 입력해주세요: \n";
  cout <<"원하시는 음식이 없다면 0을 입력해주세요:";
  cin >> idx;
  if(idx == 0)
  {
    return insertNewFood(vec);
  } else 
  {
    readFile.open("dataBase.txt");
    if(readFile.is_open())
    {
      string str;
      for(int i = 1; i < idx; i++)
      {
        for(int j = 1; j <= 5; j++)
        {
          getline(readFile, str);
        }
      }
    }
    string name;
    string tmp;
    int kcal, carbo, protein, fat;
    getline(readFile, name);
    getline(readFile, tmp);
    kcal = stoi(tmp);
    getline(readFile, tmp);
    carbo = stoi(tmp);
    getline(readFile, tmp);
    protein = stoi(tmp);
    getline(readFile, tmp);
    fat = stoi(tmp);
    Food * food = new Food(name, kcal, carbo, protein,fat);
    vec.push_back(food);
    readFile.close();
  }
}


void showMenu()
{
  vector<Food*> container;
  while(1)
  {
    int n;
    cout << "원하는 동작의 번호를 입력해주세요\n";
    cout << "1. 먹은 음식 입력하기\n";
    cout << "2. 하루동안 먹은 음식 출력하기\n";
    cout << "3. 목록에서 먹은 음식 선택하기\n";
    cout << "4. 프로그램 종료\n";
    cout << "번호를 입력해주세요: \n";
    cout << "------------------------------------------------------------\n";
    cin >> n;
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
      case 3:
      {
        cout << "------------------------------------------------------------\n";
        cout << "데이터베이스에서 음식을 선택합니다.\n";
        choseeFood(container);
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