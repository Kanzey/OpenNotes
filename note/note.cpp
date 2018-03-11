#include "note.h"

Note::Note(quint32 id, QString header, QString text, QString tags):
    id(id), header(header), text(text)
{
    this->tags= tags.split(',',QString::SkipEmptyParts);
}
