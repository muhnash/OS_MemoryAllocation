#ifndef MEMORY_H
#define MEMORY_H

#include<QString>
#include<QList>
#include "entity.h"


bool less_address(Entity a,Entity b);
bool less_size(Entity a,Entity b);
class Memory
{

private:
   //QList<Entity> mem;
public:
    QList<Entity> mem;
    void push_element(Entity x);
   // Memory(QList<Entity> holes);
    void remove_entity(QString s);
   //-------
    friend class Allocation;

};

#endif // MEMORY_H
