#ifndef Anima_h
#define Anima_h
class Anima
{
public:

    int index;
    int frames;
    int speed;

    Anima(){}
    Anima(int i, int f, int s)
    {
        index = i ;
        frames = f;
        speed = s;
    }
};

#endif // Anima_h
