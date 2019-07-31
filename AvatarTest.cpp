#include <boost/test/unit_test.hpp>
#define BOOST_TEST_MODULE Avatar
#define BOOST_TEST_DYN_LINK
#include <Avatar.hpp>

Avatar j1(0,"src/robot_l1.bmp",200,200);

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_niveau() == 0);
}

j1.set_x(20);

j1.set_y(20);


BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_position() == (20,20);
}

j1.set_nb_meca(4);

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_nb_meca() == 4;
}

j1.set_nb_elec(4);

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_nb_elec() == 4;
}

j1.set_nb_arme(3);

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_nb_arme() == 3;
}

j1.maj_niveau();

BOOST_AUTO_TEST_CASE(universeInOrder){
    BOOST_CHECK(j1.get_niveau() == 3);
}
