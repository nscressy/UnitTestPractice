/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/*TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}*/

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, smoke_testy)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, hasULGood)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Hello");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, hasULNoUpper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hello");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, hasULNoLower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HELLO");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, hasULnull)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, hasULmid)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("heLLo");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, hasULSpecialCharFail)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("H3LLO");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, hasULSpecialCharSuccess)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("H3lLO");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, hasULSpacesSuccess)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("    Hello   ");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, HasULSpacesFail)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("   hell   o   ");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, construct)
{
	Password my_password;
	bool actual = (my_password.authenticate("ChicoCA-95929"));
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, construct2)
{
	Password my_password;
	bool actual = (my_password.authenticate("Hello"));
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set1)
{
	Password my_password;
	my_password.set("Hellowor");
	bool actual = (my_password.authenticate("Hellowor"));
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set2)
{
	Password my_password;
	my_password.set("HHHellow");
	bool actual = (my_password.authenticate("HHHellow"));
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, se3)
{
	Password my_password;
	my_password.set("HHHellow");
	my_password.set("HHHellow");
	bool actual = (my_password.authenticate("HHHellow"));
	ASSERT_EQ(true,actual);
}
