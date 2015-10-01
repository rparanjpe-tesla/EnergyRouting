#ifndef COST_H
#define COST_H

#include "../typedefs.h"

struct Cost
{
    Cost();
    explicit Cost(unsigned energy,
                  unsigned time)
        : energy(energy), time(time)
    {
    }

    unsigned energy;
    unsigned time;

};

#endif // COST_H
