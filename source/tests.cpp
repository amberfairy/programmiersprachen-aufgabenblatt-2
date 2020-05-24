#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
//#include <iostream>

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
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}