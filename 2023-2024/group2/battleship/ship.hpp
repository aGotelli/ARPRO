#ifndef SHIP_HPP
#define SHIP_HPP



struct Ship {
    Ship(unsigned int t_length,
         char t_ID)
    {
        m_length = t_length;
        m_ID = t_ID;
    }

    unsigned int m_length;
    char m_ID;
};

#endif // SHIP_HPP
