#ifndef ENTITY_H
#define ENTITY_H

#include<QString>
class Entity
{
private:
    bool type=false; // true: Process , false: Hole
    QString name;
    int base_address;
    int size;

public:
    Entity(bool t);
    void set_type(bool t);
    void set_name(QString s);
    void set_base_address(int x);
    void set_size(int x);

    bool get_type();
    QString get_name();
    int get_base_address();
    int get_size();
};
#endif // ENTITY_H
