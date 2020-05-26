#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include <iostream>

Vec2 a; //erstellt neues Vec2 mit a.x == 0.0f und b.x == 0.0f    // +
Vec2 b{ 5.1f , -9.3f }; // -..- mit Approx(b.x) == 5.1f und Approx(b.y) == -9.3f    // + // -
Vec2 c{ 6.1f , -0.3f };       // -
Vec2 e = { 5.0f , -4.0f };    // *
Vec2 d{ 42.0f , -21.0};       // /

TEST_CASE("describe_myVec", "[myVec]") {

    REQUIRE(0.0f == a.x);               //2.2
    REQUIRE(0.0f == a.y);
    REQUIRE(5.1f == Approx(b.x));
    REQUIRE(-9.3f == Approx(b.y));
                                        //2.3
    a = { -1.1f , 3.3f };
    a += b;                                         // x = -1.1 + 5.1 , y = 2.3 + (-9.3)
    REQUIRE(a.x == Approx(4.0f));
    REQUIRE(a.y == Approx(-6.0f));
    a = { -1.1f , 3.3f };
    b += a;
    REQUIRE(b.x == Approx(4.0f));                   // x = 5.1 + (-1.1) , y = -9.3 + 3.3
    REQUIRE(b.y == Approx(-6.0f));


    c -= b;                                         // x = 6.1 - 4.0 , y = -0.3 - (-6.0)
    REQUIRE(c.x == Approx(2.1f));
    REQUIRE(c.y == Approx(5.7f));


    e *= -5.0f;
    REQUIRE(e.x == Approx(-25.0f));                 // x = 5 * (-5) , y = -4 * (-5)
    REQUIRE(e.y == Approx(20.0f));
    e *= 0;
    REQUIRE(e.x == 0);                              // x = -25 * 0 , y = 20 * 0
    REQUIRE(e.y == 0);
    e = { 5.0f , -4.0f };
    e *= 2.1f;
    REQUIRE(e.x == Approx(10.5f));                 // x = 5 * 2.1 , y = -4 * 2.1
    REQUIRE(e.y == Approx(-8.4f));


    d /= 4.2f;
    REQUIRE(d.x == Approx(10.0f));                 // x = 42 / 4.2 , y = 21 / 4.2
    REQUIRE(d.y == Approx(-5.0f));
    d /= -10.0f;
    REQUIRE(d.x == Approx(-1.0f));                // x = 10 / (-10) , y = -5 / (-10)
    REQUIRE(d.y == Approx(0.5f));

    REQUIRE((d /= 0).x == Approx(-1.0f));                   // -1/0 bzw. 0.5/0 Fehler!! Undef! -> Fehlermeldung
    REQUIRE((d /= 0).y == Approx(0.5f));                    // Vec2 d bleibt gleich!
    d = { 0 , 0 };
    d /= 5.7f;
    REQUIRE(d.x == Approx(0.0f));                // x = 0 / 5.7f , y = 0 / 5.7f
    REQUIRE(d.y == Approx(0.0f));


    Vec2 e = { -4.2f , 2.4f };        //2.4
    Vec2 f = { 6.2f , -8.4f };
    REQUIRE((e + f).x == Approx(2.0f));         // x = -4.2 + 6.2 , y = 2.4 + (-8.4)
    REQUIRE((e + f).y == Approx(-6.0f));
    REQUIRE((f + e).x == Approx(2.0f));         // x = 6.2 + (-4.2) , y = -8.4 + 2.4
    REQUIRE((f + e).y == Approx(-6.0f));

    REQUIRE((e - f).x == Approx(-10.4f));       // x = -4.2 - 6.2 , y = 2.4 - (-8.4)
    REQUIRE((e - f).y == Approx(10.8f));
    REQUIRE((f - e).x == Approx(10.4f));        // x = 6.2 - (-4.2) , y = -8.4 - 2.4
    REQUIRE((f - e).y == Approx(-10.8f));

    REQUIRE((e * -1.5f).x == Approx(6.3f));     // x = -4.2 * (-1.5) , y = 2.4 * (-1.5)
    REQUIRE((e * -1.5f).y == Approx(-3.6f));
    REQUIRE((e * 0.0f).x == Approx(0.0f));
    REQUIRE((e * 0.0f).y == Approx(0.0f));
    REQUIRE((e * 2.5f).x == Approx(-10.5f));     // x = -4.2 * 2.5 , y = 2.4 * 2.5
    REQUIRE((e * 2.5f).y == Approx(6.0f));


    REQUIRE((-1.5f * e).x == Approx(6.3f));     // x = -1.5 * 4.2 , y = -1.5 * 2.4
    REQUIRE((-1.5f * e).y == Approx(-3.6f));
    REQUIRE((0.0f * e).x == Approx(0.0f));
    REQUIRE((0.0f * e).y == Approx(0.0f));
    REQUIRE((2.5f * e).x == Approx(-10.5f));     // x = 2.5 * (-4.2), y = 2.5 * 2.4
    REQUIRE((2.5f * e).y == Approx(6.0f));


    e = { 3.0f , 4.5f };
    REQUIRE((e / 0.5).x == Approx(6.0f));       // x = 3.0 / 0.5 , y = 4.5 / 0.5
    REQUIRE((e / 0.5).y == Approx(9.0f));
    REQUIRE((e / 0).x == Approx(3.0f));                  // x = 3.0 / 0 , y = 4.5 / 0 -> Fehler!!
    REQUIRE((e / 0).y == Approx(4.5f));                  // Fehlermeldung+Ausgabe des Ursprünglichen wertes (e)
    REQUIRE((e / -1.5).x == Approx(-2.0f));     // x = 3.0 / (-1.5) , y = 4.5 / (-1.5)
    REQUIRE((e / -1.5).y == Approx(-3.0f));


    Mat2 i;                             //2.5
    Mat2 j = { 3 , 4 , 2, 3 };
    Mat2 k = { 1 , 2, 3 , 4 };

    REQUIRE((j * k).e_00 == Approx(15.0f));                          
    REQUIRE((j * k).e_01 == Approx(22.0f));
    REQUIRE((j * k).e_10 == Approx(11.0f));
    REQUIRE((j * k).e_11 == Approx(16.0f));

    j = { -2 , -4 , 0 , 2 };
    k = { 0.5f , 2 , -9 , 0 };

    REQUIRE((j * k).e_00 == Approx(35.0f));
    REQUIRE((j * k).e_01 == Approx(-4.0f));
    REQUIRE((j * k).e_10 == Approx(-18.0f));
    REQUIRE((j * k).e_11 == Approx(0.0f));

    REQUIRE((j * i).e_00 == j.e_00);
    REQUIRE((j * i).e_01 == j.e_01);
    REQUIRE((j * i).e_10 == j.e_10);
    REQUIRE((j * i).e_11 == j.e_11);


    i *= j;
    REQUIRE(i.e_00 == Approx(-2.0f));
    REQUIRE(i.e_01 == Approx(-4.0f));
    REQUIRE(i.e_10 == Approx(0.0f));
    REQUIRE(i.e_11 == Approx(2.0f));
    j *= k;
    REQUIRE(j.e_00 == Approx(35.0f));
    REQUIRE(j.e_01 == Approx(-4.0f));
    REQUIRE(j.e_10 == Approx(-18.0f));
    REQUIRE(j.e_11 == Approx(0.0f));

    
    k = { 0.5f , 2 , -9 , 0 };    // 2.6
    f = { 6.2f , -8.4f };
    
    Vec2 g = { 0 , 4.5f };
    Vec2 l = k * g;
    REQUIRE(l.x == 9.0f);                           // l = { g.x*k.e_00 + g.y*k.e_01 , g.x*k.e_10 + g.y*k.e_11}
    REQUIRE(l.y == 0.0f);                           // l = {     0      +     9      ,     0      +    0      }
    

    Mat2 m;
    Mat2 n = { 7.0f , -2.5f , 0.0f , 1.5f };
    REQUIRE(transpose(m).e_01 == m.e_01);           // m =  1  0 , trans(m) = 1  0  , die 0en werden getauscht und
    REQUIRE(transpose(m).e_10 == m.e_10);           //      0  1              0  1    die Hauptdiag.(1) bleibt gleich!

    REQUIRE(transpose(n).e_00 == Approx(7.0f));     // m = 7.0   0.0  ,  trans(m) = 7.0  -2.5 
    REQUIRE(transpose(n).e_01 == Approx(0.0f));     //    -2.5   1.5                0.0   1.5
    REQUIRE(transpose(n).e_10 == Approx(-2.5f));
    REQUIRE(transpose(n).e_11 == Approx(1.5f));

    Mat2 o = { -2.0f , 4.0f , 3.5f , 5.5f };
    REQUIRE(n.det() == Approx(10.5f));              // n = 7*1.5 - (-2.5)*0 = 10.5
    REQUIRE(m.det() == Approx(1.0f));               // m = {1,0,0,1} -> 1*1 - 0*0 = 1
    REQUIRE(o.det() == Approx(-25.0));              // o = -2*5.5 - 4*3.5 = -11-14 = -25

    //n = { 7.0f , -2.5f , 0.0f , 1.5f };   -> A(dach)^T = {1.5f , 2.5f , -0.0f , 7.0f}
    REQUIRE(inverse(n).e_00 == Approx(1.5f/10.5f)); // 1/det(n) = 1/10.5  ,  1/10.5 * A(dach)^T
    REQUIRE(inverse(n).e_01 == Approx(2.5f/10.5f));
    REQUIRE(inverse(n).e_10 == Approx(0.0f/10.5f));
    REQUIRE(inverse(n).e_11 == Approx(7.0f/10.5f));

    // m = { 1.0f , 0.0f , 0.0f , 1.0f }  , m.det = 1.0f, A(dach)^T = {1.0f , -0.0f , -0.0f , 1.0f} = m
    REQUIRE(inverse(m).e_00 == Approx(1.0f / 1.0f));
    REQUIRE(inverse(m).e_01 == Approx(0.0f));
    REQUIRE(inverse(m).e_10 == Approx(0.0f));
    REQUIRE(inverse(m).e_11 == Approx(1.0f));

    Color c1;
    Color c2 = { 2.5f , -3.6f , 0.0f };
    REQUIRE(c1.r == 0.5f);
    REQUIRE(c1.g == 0.5f);
    REQUIRE(c1.b == 0.5f);

    REQUIRE(c2.r == 2.5f);
    REQUIRE(c2.g == -3.6f);
    REQUIRE(c2.b == 0.0f);

    
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}