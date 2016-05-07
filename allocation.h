#ifndef ALLOCATION_H
#define ALLOCATION_H

#include<QList>
#include "memory.h"
#include "entity.h"

class Allocation
{
public:
    void FirstFit(Memory &m,Entity x);
    void BestFit(Entity x);
    void WorstFit(Memory &m,Entity x);
};
#endif // ALLOCATION_H
