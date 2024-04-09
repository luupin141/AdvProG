#ifndef Vector2D_h
#define Vector2D_h
#include<iostream>
class Vector2D
{
    public:
    double x, y;

    Vector2D();
    Vector2D(double x, double y);

    Vector2D& Plus(const Vector2D& vect);
    Vector2D& Minus(const Vector2D& vect);
    Vector2D& Multiply(const Vector2D& vect);
    Vector2D& Divide(const Vector2D& vect);

    friend Vector2D& operator + (Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator - (Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator * (Vector2D& v1, Vector2D& v2);
    friend Vector2D& operator / (Vector2D& v1, Vector2D& v2);

    Vector2D& operator +=(const Vector2D& vect);
    Vector2D& operator -=(const Vector2D& vect);
    Vector2D& operator *=(const Vector2D& vect);
    Vector2D& operator /=(const Vector2D& vect);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vect);
};

#endif // Vector2D_h
