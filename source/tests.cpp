#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
//#include <iostream>

Vec2 a; //erstellt neues Vec2 mit a.x == 0.0f und b.x == 0.0f
Vec2 b{ 5.1f , -9.3f }; // -..- mit Approx(b.x) == 5.1f und Approx(b.y) == -9.3f

Vec2 c{ 6.1f , -0.3f }; // -
Vec2 e = { 5.0f , -4.0f };    // *
Vec2 d{ 42.0f , -21.0}; // /

TEST_CASE("describe_myVec", "[myVec]") {
    REQUIRE(0.0f == a.x);               //2.2
    REQUIRE(0.0f == a.y);               
    REQUIRE(5.1f == Approx(b.x));       
    REQUIRE(-9.3f == Approx(b.y));
                                        //2.3
    a = { -1.1f , 3.3f };
    a += b;                                 // x = -1.1 + 5.1 , y = 2.3 + (-9.3)
    REQUIRE(a.x == 4.0f);
    REQUIRE(a.y ==-6.0f);
    a = { -1.1f , 3.3f };
    b += a;
    REQUIRE(b.x == 4.0f);                   // x = 5.1 + (-1.1) , y = -9.3 + 3.3
    REQUIRE(b.y ==-6.0f);


    c -= b;                                 // x = 6.1 - 4.0 , y = -0.3 - (-6.0)
    REQUIRE(c.x == 2.1f);
    REQUIRE(c.y == 5.7f);


    e *= -5;
    REQUIRE(e.x == -25);                   // x = 5 * (-5) , y = -4 * (-5)
    REQUIRE(e.y == 20);
    e *= 0;
    REQUIRE(e.x == 0);                     // x = -25 * 0 , y = 20 * 0
    REQUIRE(e.y == 0);
    e = { 5.0f , -4.0f };
    e *= 20.1f;
    REQUIRE(e.x == 100.5f);                // x = 5 * 20.1 , y = -4 * 20.1
    REQUIRE(e.y == -80.4f);


    d /= 4.2f;
    REQUIRE(d.x == 10.0f);                 // x = 42 / 4.2 , y = 21 / 4.2
    REQUIRE(d.y == -5.0f);
    d /= -10.0f;
    REQUIRE(d.x == -1.0f);                // x = 10 / (-10) , y = -5 / (-10)
    REQUIRE(d.y == 0.5f);

    REQUIRE((d /= 0).x == d.x);           // -1/0 bzw. 0.5/0 Fehler!! Undef! -> Fehlermeldung
    REQUIRE((d /= 0).y == d.y);           // Vec2 d bleibt gleich!

    d = { 0 , 0 };
    d /= 5.7f;
    REQUIRE(d.x == 0.0f);                 // x = 0 / 5.7f , y = 0 / 5.7f
    REQUIRE(d.y == 0.0f);
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}