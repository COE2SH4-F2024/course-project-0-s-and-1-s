#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.]
#include <stdexcept>
#include <iostream>

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    for (int i = 0; i < arrayCapacity; i++)
    {
        aList[i] = objPos();
    }

}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;

}

int objPosArrayList::getSize() const
{
    return listSize;

}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        for (int i = listSize ; i > 0; i-- )
        {
            aList[i] = aList[i-1];

        }
        aList[0]=thisPos;
        listSize++;
        
    }
    else
    {
        std::cerr<<"Error:List is full, cannot insert at head."<<std::endl;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
         aList[listSize] = thisPos;
         listSize++;
    }
    else
    {
        std::cerr<<"Error:List is full, cannot insert at tail."<<std::endl;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize > 0)
    {
        for (int i = 0 ; i < listSize -1; i++)
        {
            aList[i] = aList[i+1];
        }
         listSize--;
    }
    else
    {
        std::cerr<<"Error:List is empty, cannot remove head."<<std::endl;
    }

}

void objPosArrayList::removeTail()
{
    if(listSize>0)
    {
        listSize--;
    }
    else
    {
        std::cerr<<"Error:List is empty, cannot remove tail."<<std::endl;
    }

}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0)
    {
        return aList[0];
    }
    else
    {
        throw std::out_of_range("Error: List is empty, no head element");
    }
    
}

objPos objPosArrayList::getTailElement() const
{
    if(listSize > 0)
    {
        return aList[listSize - 1];
    }
    else
    {
        throw std::out_of_range("Error: List is empty, no tail element");
    }

}

objPos objPosArrayList::getElement(int index) const
{
    if(index >= 0 && index < listSize)
    {
        return aList[index];
    }
    else
    {
        throw std::out_of_range("Error: index out of range");
    }
}
