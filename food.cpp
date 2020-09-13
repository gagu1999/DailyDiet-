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
  kcal = carbo = protein = fat = 0;
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

void choseeFood(vector<Food *> & vec, vector<Food * > & storage)
{
  int idx = 1;
  ifstream readFile;
  readFile.open("dataBase.txt");
  if(readFile.is_open() && storage.size() == 0) // 맨처음 불러와서 storage가 비어있는 경우
  {
    while(!readFile.eof())
    {
      string name;
      string tmp;
      int kcal, carbo, protein, fat;
      getline(readFile, name);
      if(readFile.eof())
      {
        break;
      }
      cout << idx << "번 음식: " << name <<"\n";
      idx++;
      getline(readFile, tmp);
      kcal = stoi(tmp);
      getline(readFile, tmp);
      carbo = stoi(tmp);
      getline(readFile, tmp);
      protein = stoi(tmp);
      getline(readFile, tmp);
      fat = stoi(tmp);
      Food * food = new Food(name, kcal, carbo, protein,fat);
      storage.push_back(food);
    }
  } else // 이전에 storage를 채워놓은 경우
  {
    for(int i = 0; i < storage.size(); i++)
    {
      cout << (i + 1) << "번 음식: " << storage[i]->getName() << "\n";
    }
  }
  readFile.close();
  cout << "음식번호를 입력해주세요\n";
  cout <<"원하시는 음식이 없다면 0을 입력해주세요\n";
  cout << "번호 입력: ";
  cin >> idx;

  while(idx < 0 || storage.size() < idx)
  {
    cout << "잘못된 입력입니다. 다시 입력해주세요\n";
    cout << "번호 입력: ";
    cin >> idx;
  }
  if(idx == 0)
  {
    return insertNewFood(vec);
  } else 
  {
    vec.push_back(storage[idx - 1]); // 위에서 구한idx로 출력하면 되지롱
  }
}


void showMenu()
{
  vector<Food*> today; //오늘 먹은 음식을 담을 벡터
  vector<Food*> storage; // 이전에 먹었던 음식들을 담아놓은 벡터
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
    while(n < 1 || n > 4)
    {
      cout << "잘못된 입력입니다. 다시 입력해주세요\n";
      cout << "번호 입력: ";
      cin >> n;
    }

    switch(n)
    {
      case 1:
      {
        cout << "------------------------------------------------------------\n";
        cout << "오늘 먹은 음식을 추가합니다.\n";
        insertNewFood(today);
        cout << "------------------------------------------------------------\n";
        break;
      }
      case 2:
      {
        cout << "------------------------------------------------------------\n";
        cout << "오늘 하루동안 먹은 모든 음식을 출력합니다.\n";
        showDailyDietInfo(today);
        cout << "------------------------------------------------------------\n";
        break;
      }
      case 3:
      {
        cout << "------------------------------------------------------------\n";
        cout << "데이터베이스에서 음식을 선택합니다.\n";
        choseeFood(today, storage);
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