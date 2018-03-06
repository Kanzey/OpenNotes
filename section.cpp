#include "section.h"

Section::Section(qint32 id, QString name, QString color):
    id(id), name(name), color(color)
{
    tabColor=QColor::fromHsvF(this->color.hueF(),0.12,0.88);
}

Section::Section()
{

}
