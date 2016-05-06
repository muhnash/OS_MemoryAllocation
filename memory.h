#ifndef MEMORY_H
#define MEMORY_H

#include<QString>
#include<QList>
#include "entity.h"

class Memory
{
private:
    QList<Entity> mem;
public:
    Memory();
   // void add_entity(Entity x);
    void remove_entity(QString s);
};

#endif // MEMORY_H
