#include "FitnessApp.h"

class DietPlan:Plan {
  private:
    unsigned int calories;
  public:
    DietPlan(unsigned int newCalories = 2000) {
      calories = newCalories;
    }
};