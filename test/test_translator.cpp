#include"C:\Users\Кирилл\translator\gtest\gtest.h"
#include"C:\Users\Кирилл\translator\include\translator.h"

TEST(ArithmeticExpression, can_get_infix)
{    
   ArithmeticExpression ar("1+1");

   EXPECT_EQ(ar.GetInfix(), "1+1");
}

TEST(ArithmeticExpression,throws_when_invalid_lexem)
{
    ArithmeticExpression ar("1?");

    ASSERT_ANY_THROW(ar.Parse());
}

TEST(ArithmeticExpression, throws_when_incorrect_brackets)
{
    ArithmeticExpression ar(")1");

    ASSERT_ANY_THROW(ar.Parse());
}

TEST(ArithmeticExpression, throws_when_expression_is_empty)
{
    ArithmeticExpression ar("");

    ASSERT_ANY_THROW(ar.Parse());
}
 
TEST(ArithmeticExpression, throws_when_first_lexem_is_operation)
{
    ArithmeticExpression ar("*1");

    ASSERT_ANY_THROW(ar.Parse());
}
   
TEST(ArithmeticExpression, can_get_postfix)
{
    ArithmeticExpression ar("2+2");
    ar.Token();
    ar.Parse();
    ar.ToPostfix();

    ASSERT_NO_THROW(ar.GetPostfix());
}
   
TEST(ArithmeticExpression, calculate_correctly)
{
    ArithmeticExpression ar("2+2");
    ar.Token();
    ar.Parse();
    ar.ToPostfix();
    
    EXPECT_EQ(ar.Calculate(), 4);
}

TEST(ArithmeticExpression, throws_when_div_by_zero)
{
    ArithmeticExpression ar("5/0");
    ar.Token();
    ar.Parse();
    ar.ToPostfix();

    ASSERT_ANY_THROW(ar.Calculate());
}

