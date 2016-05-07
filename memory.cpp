#include "memory.h"
#include <QList>
#include <QDebug>
#include <QString>


using namespace std;

bool less_address(Entity a,Entity b)
{
    if(a.get_base_address() < b.get_base_address())
        return true;
    else
        return false;
}

bool less_size(Entity a,Entity b)
{
    if(a.get_size() < b.get_size())
        return true;
    else
        return false;
}
/*
Memory::Memory(QList<Entity> holes)
{
    if(holes.empty()) {return;}

    QList<Entity>::iterator it;
    sort(holes.begin(),holes.end(), higher_address); // sort by addresses

    mem.push_back(holes.front());
    it==next(holes.begin());

    for(;it!=holes.end();++it)
    {
        int last_hole_limit = prev(it)->get_base_address() + prev(it)->get_size();
        if(it->get_base_address() > last_hole_limit ) // no need for join .. push
        {
            mem.push_back(*it);
        }
        else if(it->get_base_address() < last_hole_limit ) // 2 overlapping holes
        {
            // extend the previous ... don't push the current
            int current_hole_limit = it->get_base_address() +it->get_size();
            int new_size = prev(it)->get_size()+ (current_hole_limit - last_hole_limit);
            prev(it)->set_size(new_size);
        }
        else
        {
            // extend the previous ... delete the current
            int new_size = prev(it)->get_size()+ it->get_size();
            prev(it)->set_size(new_size);

        }

    }
}
*/
void Memory::remove_entity(QString s)
{
    // remove process
       QList<Entity>::iterator it= mem.begin();

       for(;it != mem.end(); ++it)
       {
           if(it->get_name()==s) // process found
           {
               if(it != mem.begin() && prev(it)->get_type()==false) // previous entity is hole?
               {
                   int temp_size;
                   if(next(it)!= mem.end())
                   {
                       if(next(it)->get_type()==false) // next entity is hole?
                       {
                           // extend previous .. delete current and next
                           temp_size= it->get_size() + next(it)->get_size() + prev(it)->get_size();
                           prev(it)->set_size(temp_size);
                           // hope they work :v
                           it=mem.erase(it);
                           it=mem.erase(it);
                       }
                       else
                       {
                           // extend previous .. delete currunt only
                           temp_size= it->get_size()+ prev(it)->get_size();
                           prev(it)->set_size(temp_size);
                           it=mem.erase(it);
                       }
                       //prev(it)->set_size(temp_size);
                   }
                   else
                   {
                       // extend previous .. delete currunt only
                       temp_size = it->get_size() + prev(it)->get_size();
                       prev(it)->set_size(temp_size);
                       it = mem.erase(it);

                   }

               }
               else
               {
                       if(next(it)!= mem.end() && next(it)->get_type()==false) // next entity is hole?
                       {
                           // extend the next backward .. delete current
                           int temp_size= it->get_size() + next(it)->get_size();
                           next(it)->set_base_address( it->get_base_address());
                           next(it)->set_size(temp_size);
                           it=mem.erase(it);
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

void Memory::push_element(Entity x)
{
    mem.push_back(x);
}
