#include <iostream>
#include <initializer_list>
#include <array>
#include <vector>
#include <string>
#include <cstdarg>
#include <algorithm>

using namespace std;

class Dog
{
  public:
    int age;
    string name;
    int hunger = 0;
    vector<string> dislikeFood;
    Dog (int age, string name);
    void setDislikeFood(string arg)
    {
      dislikeFood.push_back(arg);
    }
    template<typename ...disliked_foods>
    void setDislikeFood(string arg, disliked_foods&... args)
    {
      setDislikeFood(arg);
      setDislikeFood(args...);
    }
    void dogName()
    {
      cout << name << '\n';
    }
    void giveFood(string food_name, int amount_of_food);
    void fullDog()
    {
      if (hunger > 5)
      {
        cout << name << " is full." << '\n';
      }
      else
      {
        cout << name << " is not full." << '\n';
      }
    }

  private:
    void ateFood(string food_name)
    {
      cout << name << " ate the " << food_name << '\n'; 
    }
};

void Dog::giveFood(string food_name, int amount_of_food)
{
if (find(dislikeFood.begin(), dislikeFood.end(), food_name) != dislikeFood.end())
  {
    cout << name << " did not eat the " << food_name << '\n';
  }
  else
  {
    hunger += amount_of_food;
    ateFood(food_name);
    fullDog();
  }
}

Dog::Dog (int age_init, string name_init)
{
  age = age_init;
  name = name_init;
}

int main()
{
  Dog ralph(10, "ralph");
  // string chicken = "chicken";
  // string peppers = "peppers";
  ralph.setDislikeFood("chicken", "peppers", "chocolate");
  ralph.dogName();
  ralph.giveFood("chicken", 3);
  ralph.giveFood("steak", 2);
  ralph.giveFood("chocolate", 5);
  ralph.giveFood("cheese", 5);
}