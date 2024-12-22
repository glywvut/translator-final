#include "gtest.h"
#include "term.h"

TEST(Number, can_create_number)
{
	ASSERT_NO_THROW(Number numb(1));
}

TEST(Number, can_get_value)
{
	Number numb(1);

	EXPECT_EQ(numb.get_value(), 1);
}

TEST(Operation, can_create_operation)
{
	ASSERT_NO_THROW(Operation op('+'));
}

TEST(Operation, can_get_operation)
{
	Operation op('+');

	EXPECT_EQ(op.get_operation(), '+');
}

TEST(OpenBracket, can_create_open_bracket)
{
	ASSERT_NO_THROW(OpenBracket ob);
}

TEST(OpenBracket, can_get_open_bracket)
{
	OpenBracket ob;
	EXPECT_EQ(ob.get_bracket(), '(');
}

TEST(ClosedBracket, can_create_closed_bracket)
{
	ASSERT_NO_THROW(ClosedBracket cb);
}

TEST(CloseBracket, can_get_close_bracket)
{
	ClosedBracket cb;

	EXPECT_EQ(cb.get_bracket(), ')');
}
