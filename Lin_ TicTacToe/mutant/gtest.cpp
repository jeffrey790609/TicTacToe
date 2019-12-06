#include <gtest/gtest.h>
#include "easylevel.h"
#include "easylevel.cpp"
#include "tictactoe.cpp"
#include "tictactoe.h"
#include "getch.cpp"


/*
int foobar(void)
{
    return 1;
}

TEST(foobar, test)
{
    ASSERT_EQ(1, foobar());
}
*/

TEST(iswinning, test1)
{
    easylevel abc;
    EXPECT_EQ(0, abc.is_winning('X'));
       
}

TEST(makemove, test1)
{
    easylevel abc;
    EXPECT_EQ(1, abc.make_move());
}



TEST(ifwon, test1)
{
    char grid[3][3];
    tictactoe abc;
    grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] != '-';
    bool result = abc.if_won();
    EXPECT_TRUE(result == 1);
       
}

TEST(lastmove, test1)
{
    char c = 'X';
    tictactoe abc;
    char grid[3][3];
    grid[0][0] = '-';
    //abc->do_last_move('X');
    EXPECT_EQ(c, abc.do_last_move('X'));
       
}
TEST(printgrid, test1)
{
    tictactoe abc;
    EXPECT_EQ(0, abc.print_grid());
       
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}