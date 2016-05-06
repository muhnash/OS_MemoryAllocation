#ifndef ALLOCATION_H
#define ALLOCATION_H

#include<QList>
#include "memory.h"
#include "entity.h"

class Allocation
{
    friend class Memory;
public:
    void FirstFit(Entity x);
    void BestFit(Entity x);
    void WorstFit(Entity x);
};
#endif // ALLOCATION_H
