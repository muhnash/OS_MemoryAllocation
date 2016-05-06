#include"entity.h"
#include"QString"

Entity::Entity(bool t)
{
    type=t;
}
void Entity::set_type(bool t)
{
    type=t;
}

void Entity::set_name(QString s)
{
    name=s;
}
void Entity::set_base_address(int x)
{
    base_address=x;
}
void Entity::set_size(int x)
{
    size=x;
}

bool Entity::get_type()
{
    return type;
}
QString Entity::get_name()
{
    return name;
}
int Entity::get_base_address()
{
    return base_address;
}
int Entity::get_size()
{
    return size;
}

