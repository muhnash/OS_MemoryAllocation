#include "allocation.h"
#include <QList>
#include <algorithm>
#include <memory.h>
#include <qalgorithms.h>

void Allocation::FirstFit(Memory &m ,Entity x)
{
    QList<Entity>::iterator it= m.mem.begin();
    qSort(m.mem.begin(),m.mem.end(),less_address); // sort by addresses
    for(;it != m.mem.end();++it)
    {
        if(it->get_type() || it->get_size() < x.get_size() ) continue;  //skip processes & small holes

        if(it->get_size()==x.get_size())
        {
            // perfect hole !! same size & same base address .. just change type and name
            it->set_type(true);
            it->set_name(x.get_name());
            break;
        }
        else
        {
            // create new hole
            Entity temp(false);
            temp.set_size(it->get_size() - x.get_size());

            m.mem.push_back(temp);

            // allocate
            it->set_type(true);
            it->set_name(x.get_name());
            it->set_size(x.get_size());
            break;
        }
    }


}
//void Allocation::WorstFit(Memory &m ,Entity x)
//{

//}

void Allocation::BestFit(Memory &m,Entity x)
{

    QList<Entity>::iterator it= m.mem.begin();
    int min_size = -1;
    int address_of_min_size;
    if (x.get_size()>= it->get_size())
    {
         min_size=it->get_size();
         address_of_min_size = it->get_base_address() ;
    }
    for(;it != m.mem.end();++it)
    {
        if((it->get_size() < min_size) && (x.get_size() >= it->get_size()))
        {
            min_size = it->get_size();
            address_of_min_size = it->get_base_address() ;
        }
    }
    if (min_size == -1)//kda yb2a mfysh mkan fy el mem kolha as8r mn size el process
    {
        return;
    }
    //prefect case
    else if (x.get_size()==min_size)
    {
        it->set_type(true);
        it->set_name(x.get_name());
    }
    else
    {

        // create new hole
        Entity temp(false);
        temp.set_size(it->get_size() - x.get_size());

        m.mem.push_back(temp);

        // allocate
        it->set_type(true);
        it->set_name(x.get_name());
        it->set_size(x.get_size());
    }
}
