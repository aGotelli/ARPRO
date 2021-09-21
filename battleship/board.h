#ifndef BOARD_H
#define BOARD_H






enum class BoxContent {
    AIRCRAFT,
    CRUISE,
    DESTROYER,
    SUBMARINE,
    SEA
};

struct Box {
    Box()=default;

    //  The structure members
    bool hit { false };
    BoxContent content { BoxContent::SEA };

    char displayBoxContent()
    {
        switch (content) {
            case BoxContent::AIRCRAFT :
                return 'A';
            case BoxContent::CRUISE :
                return 'C';
            case BoxContent::DESTROYER :
                return 'D';
            case BoxContent::SUBMARINE :
                return 'S';
        default:
            return '~';
        }
    }
};

#endif // BOARD_H
