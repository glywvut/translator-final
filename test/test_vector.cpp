#include "vector_and_stack.h"
#include <gtest.h>

TEST(Vector, can_vector_with_positive_len) {

	ASSERT_NO_THROW(Vector<int> vector(1));
}

TEST(Vector, cant_create_vector_with_negative_len) {

	ASSERT_ANY_THROW(Vector<int> vector(-5));
}

TEST(Vector, create_vector_with_array) {
	int* arr = new int[3] { 1, 2, 3 };

	ASSERT_NO_THROW(Vector<int> vector(arr, 3));
	delete[] arr;
}

TEST(Vector, can_create_copied_vector)
{
	Vector<int> v(10);

	ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(Vector, copied_vector_is_equal_to_source_one)
{
	Vector<int> v(10);
	v[0] = 1;
	Vector<int> vcpy(v);

	EXPECT_EQ(v, vcpy);
}

TEST(Vector, copied_vector_has_its_own_memory)
{
	Vector<int> v(10);
    Vector<int> vcpy(v);

	EXPECT_NE(&v, &vcpy);
}

TEST(Vector, can_get_size)
{
	Vector<int> v(5);

	EXPECT_EQ(5, v.size());
}

TEST(Vector, can_get_capacity)
{
	Vector<int> v(10);

	EXPECT_EQ(22, v.getcapacity());
}

TEST(Vector, can_set_and_get_element)
{
    Vector<int> v(5);
    v[0] = 5;

    EXPECT_EQ(5, v[0]);
}

TEST(Vector, can_assign_vector_to_itself)
{
    Vector<int> v(10);
    v[0] = 1;
    Vector<int> vcpy(v);

    EXPECT_EQ(v, vcpy);
}

TEST(Vector, can_assign_vectors_of_equal_size)
{
    Vector<int> v1(10);
    Vector<int> v2(10);
    v2[0] = 1;
    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(Vector, compare_equal_vectors_return_true)
{
    int* arr1 = new int[3] {1, 2, 3};
    Vector<int> v1(arr1, 3);
    delete[] arr1;
    int* arr2 = new int[3] {1, 2, 3};
    Vector<int> v2(arr2, 3);
    delete[] arr2;

    EXPECT_TRUE(v1 == v2);
}

TEST(Vector, compare_vector_with_itself_return_true)
{
    Vector<int> v(10);
    v[0] = 1;

    EXPECT_TRUE(v == v);
}

TEST(Vector, vectors_with_different_size_are_not_equal)
{
    Vector<int> v1(10);
    Vector<int> v2(5);

    EXPECT_FALSE(v1 == v2);
}

TEST(Vector, can_check_for_full)
{
    Vector<int> v(10);
    EXPECT_FALSE(v.IsFull());
}

TEST(Vector, can_check_for_empty)
{
    Vector<int> v;

    EXPECT_TRUE(v.IsEmpty());
}

TEST(Vector, can_push_back)
{
    int* arr1 = new int[3] {1, 2, 3};
    Vector<int> v1(arr1, 3);
    delete[] arr1;
    int* arr2 = new int[4] {1, 2, 3, 4};
    Vector<int> v2(arr2, 4);
    delete[] arr2;
    v1.push_back(4);

    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_push_front)
{
    int* arr1 = new int[3] {2,3,4};
    Vector<int> v1(arr1, 3);
    delete[] arr1;
    int* arr2 = new int[4] {1,2,3,4};
    Vector<int> v2(arr2, 4);
    delete[] arr2;
    v1.push_front(1);

    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_pop_back)
{
    int* arr1 = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v1(arr1, 5);
    delete[] arr1;
    int* arr2 = new int[4] {1, 2, 3, 4};
    Vector<int> v2(arr2, 4);
    delete[] arr2;
    v1.pop_back();

    EXPECT_EQ(v1, v2);
}

TEST(Vector, throws_when_pop_back_elem_from_empty_vector)
{
    Vector<int> v;

    ASSERT_ANY_THROW(v.pop_back());
}

TEST(Vector, can_pop_front)
{
    int* arr = new int[3] {8, 10, 12};
    Vector<int> v1(arr, 3);
    delete[] arr;
    int* arr2 = new int[2] {10, 12};
    Vector<int> v2(arr2, 2);
    delete[] arr2;
    v1.pop_front();

    EXPECT_EQ(v1, v2);
}

TEST(Vector, throws_when_pop_front_elem_from_empty_vector)
{
    Vector<int> v;

    ASSERT_ANY_THROW(v.pop_front());
}

TEST(Vector, can_insert_elem)
{
    int* arr = new int[3] {1, 2, 4};
    Vector<int> v1(arr, 3);
    delete[] arr;
    int* arr2 = new int[4] {1, 2, 3, 4};
    Vector<int> v2(arr2, 4);
    delete[] arr2;
    v1.insert(3, 2);

    EXPECT_EQ(v1, v2);
}

TEST(Vector, can_erase)
{
    int* arr = new int[3] {1, 2, 3};
    Vector<int> v1(arr, 3);
    delete[] arr;
    int* arr2 = new int[2] {1, 3};
    Vector<int> v2(arr2, 2);
    delete[] arr2;
    v1.erase(1);

    EXPECT_EQ(v1, v2);
}

TEST(Vector, throws_when_erase_elem_from_empty_vector)
{
    Vector<int> v;

    ASSERT_ANY_THROW(v.erase(0));
}