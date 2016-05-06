#include "allocation.h"
#include <QList>

void FirstFit(Entity x)
{
    QList<Entity>::iterator it=Memory.mem.begin();
    for(;it != mem.end();++it)
    {
        if(it->get_type() || it->get_size() < x.get_size() ) continue;  //skip processes & small holes

        if(it->get_size()==x.get_size())
        {
            // perfect hole !! same size & same base address .. just change type and name
            it->set_type(true);
            it->set_name(x.get_name());
        }
        else
        {
            // create new hole
            Entity temp(false);
            temp.set_size(it->get_size() - x.get_size());

            Memory.mem.insert(next(std::it),temp);

            // allocate
            it->set_type(true);
            it->set_name(x.get_name());
            it->set_size(x.get_size());

        }
    }


}
