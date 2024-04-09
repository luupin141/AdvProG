#include"Vector2D.h"

Vector2D::Vector2D()
{
    x= 0.0f;
    y= 0.0f;
}

Vector2D::Vector2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::Plus(const Vector2D& vect)
{
    this->x += vect.x;
    this->y += vect.y;

    return* this;
}

Vector2D& Vector2D::Minus(const Vector2D& vect)
{
    this->x -= vect.x;
    this->y -= vect.y;

    return* this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vect)
{
    this->x *= vect.x;
    this->y *= vect.y;

    return* this;
}

Vector2D& Vector2D::Divide(const Vector2D& vect)
{
    this->x /= vect.x;
    this->y /= vect.y;

    return* this;
}

Vector2D& operator + (Vector2D& v1, Vector2D& v2)
{
    return v1.Plus(v2);
}

Vector2D& operator - (Vector2D& v1, Vector2D& v2)
{
    return v1.Minus(v2);
}

Vector2D& operator / (Vector2D& v1, Vector2D& v2)
{
    return v1.Divide(v2);
}

Vector2D& Vector2D::operator +=(const Vector2D& vect)
{
    return this->Plus(vect);
}

Vector2D& Vector2D::operator -=(const Vector2D& vect)
{
    return this->Minus(vect);
}

Vector2D& Vector2D::operator *=(const Vector2D& vect)
{
    return this->Multiply(vect);
}

Vector2D& Vector2D::operator /=(const Vector2D& vect)
{
    return this->Divide(vect);
}

Vector2D& Vector2D::operator*(const int& i)
{
    this->x *=i;
    this->y *=i;

    return *this;
}
Vector2D& Vector2D::Zero()
{
    this->x =0;
    this->y =0;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vect)
{
    stream<< "(" << vect.x << "," << vect.y << ")";
    return stream;
}





