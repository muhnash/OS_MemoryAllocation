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
    Memory(QList<Entity> holes);
    void add_entity(Entity x);
    void remove_entity(QString s);
   //-------
    void print();
    void print_n_entities();

};

#endif // MEMORY_H
