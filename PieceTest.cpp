#include <boost/test/unit_test.hpp>
#define BOOST_TEST_MODULE Piece
#define BOOST_TEST_DYN_LINK
#include <Piece.hpp>

Piece piece();

Piece.set_largeur(10);
Piece.set_longueur(10);

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(piece.get_largeur() == 10);
}

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(piece.get_longueur() == 10);
}
