#include "count.h"

int c = 0;

count::count()
{

}

void count::increase()
{
    c++;
}

void count::decrease()
{
    c--;
}

int count::get()
{
    return c;
}

