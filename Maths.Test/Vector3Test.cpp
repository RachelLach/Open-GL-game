#include "pch.h"
#include"../Maths/Vector3.h"


TEST(Vector3_Constructor, AssignsAllCommponents) {
	Vector3 v(3, 4, 5);
	EXPECT_EQ(v.x, 3);
	EXPECT_EQ(v.y, 4);
	EXPECT_EQ(v.z, 5);
}

// UniTest 
// Test and implement equality comparison
TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Vectors) {
	EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 4, 5));
	EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 2, 5));
	EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 4, 2));
	EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 2, 2));
}

// Test and implement inequality comparison 
// UniTest
// Test-Driven Development (First write the test, then the function, then clean up your code)
TEST(Vector3_InequalityComparison, Returns_True_For_Inequal_Vectors) {
	EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 2, 5));
	EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(5, 2, 5));
	EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(3, 3, 2));
	EXPECT_TRUE(Vector3(3, 4, 5) != Vector3(5, 2, 2));
}

// Test and implement negate operator
TEST(Vector3_Negate, InvertsPositiveValues) {
	EXPECT_EQ(-Vector3(3, 4, 5), Vector3(-3, -4, -5));
}

// Test and implement adding operator 
TEST(Vector3_Addition, Correctly_Sums_Up_Vector3) {
	EXPECT_EQ(Vector3(3, 4, 5) + Vector3(2, 3, 6), Vector3(5,7,11));
}

TEST(Vector3_Division, Correctly_Devide_Vector3) {
	EXPECT_EQ(Vector3(3, 4, 5) + Vector3(6, 8, 5), Vector3(0.5, 0.5, 1));
}

