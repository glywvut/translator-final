#include "vector_and_stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_check_for_empty)
{
    Stack<int> s;

    EXPECT_TRUE(s.IsEmpty());
}

TEST(Stack, can_check_for_full)
{
    Stack<int> s;

    EXPECT_FALSE(s.IsFull());
}

TEST(Stack, can_get_size)
{
   Stack<int> s;
    s.push(1);
    s.push(2);

    EXPECT_EQ(2, s.size());
}

TEST(Stack, can_get_capacity)
{
    Stack<int> s;

    ASSERT_NO_THROW(s.getcapacity());
}

TEST(Stack, can_push)
{
    Stack<int> s;
    s.push(1);
   
    ASSERT_NO_THROW(s.getcapacity());
}

TEST(Stack, can_pop)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();

    EXPECT_EQ(1, s.top());
}

TEST(Stack, throws_when_pop_empty_stack)
{
    Stack<int> s;

    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, throws_when_take_top_elem_empty_stack)
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.top());
}

TEST(Stack, can_get_top_element)
{
    Stack<int> s;
    s.push(1); s.push(2);
    EXPECT_EQ(2, s.top());
}