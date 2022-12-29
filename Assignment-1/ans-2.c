//Develop a structure to represent planets in the solar system. Each planet has fields for the planets name, its distance from the sun in miles and the number of moons it has. 
//Write a program to read the data for each planet and store. 
//Also print the name of the planet that has the highest number moons.

#include <stdio.h>
#include <stdlib.h>

struct planet
{
    char name[25];
    float distance;
    int moons;
};

int main()
{
    int i, j, n=9, high;
    struct planet p[n];
    printf("\n\n\tReading Data for 9 Planets\n");
    for (i=0;i<n;i++)
    {
        printf("\n\tEnter Planet %d Name: ", i+1);
        scanf("%s", p[i].name);
        printf("\tEnter Planet %d distance from sun (in miles): ", i+1);
        scanf("%f", &p[i].distance);
        printf("\tEnter no. of moons planet %d has: ", i+1);
        scanf("%d", &p[i].moons);
    }
    high = p[0].moons;
    j=0;
    for (i=1;i<n;i++)
    {
        if (p[i].moons>high)
        {
            high = p[i].moons;
            j=i;
        }
    }
    printf("\n\n\tPlanet %s has highest number of moons.", p[j].name);
    return 0;
}
