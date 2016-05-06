#include "memory.h"
#include <QList>
#include <QDebug>
#include <QString>

Memory::Memory(){}

void Memory::remove_entity(QString s)
{
    // remove process
    QList<Entity>::iterator it= mem.begin();

    for(;it != Processes.end(); ++it)
    {
        if(it->getName()==s) // process found
        {
            if(prev(it)->get_type()==false) // previous entity is hole?
            {
                if(next(it)!= mem.end())
                {
                    if(next(it)->get_type()==false) // next entity is hole?
                    {
                        // extend previous .. delete current and next
                    }
                    else
                    {
                        // extend previous .. delete currunt only
                    }
                }
            }
            else
            {
                    if(next(it)!= mem.end() && next(it)->get_type()==false) // next entity is hole?
                    {
                        // extend the next backward .. delete current
                    }
                    else
                    {
                        // just turn it into Hole
                        it->set_type(false);
                    }
            }
            break;
        }
    }
}



// just for dump test
void Memory::print_entities()
{
    QList<Entity>::iterator it;
    for (it =mem.begin();it != mem.end(); ++it)
    {
        qDebug() << it ->get_name()<<" - "<<it ->get_type();
    }
}
