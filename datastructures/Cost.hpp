#ifndef COST_H
#define COST_H

#include "../typedefs.h"

struct Cost
{
    Cost();
    explicit Cost(unsigned energy,
                  unsigned time)
        : m_energy(energy), m_time(time)
    {
    }

    unsigned m_energy;
    unsigned m_time;

};

#endif // COST_H
