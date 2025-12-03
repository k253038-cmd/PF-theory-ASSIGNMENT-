#include <stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus,
                   int planet, int totalPlanets) {

    if (planet > totalPlanets) {
        printf("Mission Successful: Spacecraft completed the journey!\n");
        return;
    }

   
    fuel -= consumption;

    
    if (fuel <= 0) {
        printf("Planet %d: Fuel Remaining = 0\n", planet);
        printf("Mission Failed: Fuel exhausted at planet %d.\n", planet);
        return;
    }

    if (planet % 3 == 0) {
        fuel += recharge;
    }

   
    if (planet % 4 == 0) {
        fuel += solarBonus;
    }

    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    calculateFuel(fuel, consumption, recharge, solarBonus,
                  planet + 1, totalPlanets);
}


int main() {
    int startingFuel = 500;
    int consumption = 40;
    int recharge = 25;      
    int solarBonus = 60;    
    int totalPlanets = 12;

    calculateFuel(startingFuel, consumption, recharge, solarBonus, 1, totalPlanets);

    return 0;
}

