//
// Created by SL15 on 21.06.2021.
//

#ifndef QT_REPOSITORY_H
#include "SourceFile.h"
#include <vector>
#define QT_REPOSITORY_H

template <class TElem>
class Repository{
private:
    std::vector<TElem> elements;
    virtual void load_from_file()=0;
    virtual void save_to_file()=0;
public:
    Repository(){;}
    ~Repository(){;}
    virtual bool add(const TElem& elem)=0;
};


#endif //QT_REPOSITORY_H
