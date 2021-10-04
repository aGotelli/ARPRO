#ifndef BOX_H
#define BOX_H

#include <iostream>

//  Simple way to define an object
struct Box{
    Box()=default;
    /* With the = default I specifically say that
     * the members of this object have a default initaliation.
     * With a default initialization I do not need to bother to
     * initialize the element once I create it. It is alresdy
     * done for me (and actually could bring improvement to
     * performances)
     */

    void printBoxContent(const bool hide_content)
    {
        if(hide_content){
            if(hit)
                std::cout << "X ";
            else
                std::cout << "~ ";

            return; //end function execution here
        }

        if(hit)
            std::cout << "X ";
        else {
            switch(content){
            case 1:
                std::cout << "A ";
                break;
            case 2:
                std::cout << "C ";
                break;
            case 3:
                std::cout << "D ";
                break;
            case 4:
                std::cout << "S ";
                break;
            default:
                std::cout << "~ ";
            }
        }
    }

    //  Give default initialization
    unsigned int content { 0 };
    bool hit { false };
};



#endif // BOX_H
