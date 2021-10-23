#include "pch.h"
using namespace P3_1;

	TEST(Constructor, DefaultConstructor) {
		IntVector iv1;
		ASSERT_EQ(0, iv1.getCSz());
	}

	TEST(Constructor, SoloConstructor) {
		IntVector iv2(5);
		ASSERT_EQ(1, iv2.getCSz());
		ASSERT_EQ(5, iv2.getArEl(0));
	}

	TEST(Constructor, NormalConstructor) {
		int els[3] = {15,-4, 24};
		IntVector iv3(3, els);
		ASSERT_EQ(3, iv3.getCSz());
		ASSERT_EQ(15, iv3.getArEl(0));
		ASSERT_EQ(-4, iv3.getArEl(1));
		ASSERT_EQ(24, iv3.getArEl(2));
	}

	TEST(Constructor, NormalConstructorException) {
		int els[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		ASSERT_ANY_THROW(IntVector iv3(11, els));
	}

	TEST(Method, AddElem) {
		IntVector iv4;
		ASSERT_EQ(0, iv4.getCSz());
		iv4.addEl(5);
		ASSERT_EQ(1, iv4.getCSz());
		ASSERT_EQ(5, iv4.getArEl(0));
	}

	TEST(Method, AddElemException) {
		int els[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		IntVector iv5(10, els);
		ASSERT_EQ(10, iv5.getCSz());
		ASSERT_ANY_THROW(iv5.addEl(10));
	}

	TEST(Method, Sort) {
		int els[3] = { 24,-4, 15 };
		IntVector iv6(3, els);
		ASSERT_EQ(3, iv6.getCSz());
		ASSERT_EQ(24, iv6.getArEl(0));
		ASSERT_EQ(-4, iv6.getArEl(1));
		ASSERT_EQ(15, iv6.getArEl(2));
		iv6.sort(0,2);
		ASSERT_EQ(3, iv6.getCSz());
		ASSERT_EQ(-4, iv6.getArEl(0));
		ASSERT_EQ(15, iv6.getArEl(1));
		ASSERT_EQ(24, iv6.getArEl(2));
	}

	TEST(Method, SortException) {
		IntVector iv7;
		ASSERT_ANY_THROW(iv7.sort(0, 0));
	}

	TEST(Method, MaxElem) {
		int els[4] = { 24,-4, 15, 0};
		IntVector iv8(4, els);
		ASSERT_EQ(24, iv8.maxNum());
		iv8.addEl(55);
		ASSERT_EQ(55, iv8.maxNum());
	}

	TEST(Method, MaxElemException) {
		IntVector iv9;
		ASSERT_ANY_THROW(iv9.maxNum());
	}

	TEST(Method, SumVectors) {
		int els1[3] = { 24,-4, 15 };
		IntVector iv10(3, els1);
		int els2[3] = { 1, 1, 1 };
		IntVector iv11(3, els2);
		iv10.sum(iv11);
		ASSERT_EQ(25, iv10.getArEl(0));
		ASSERT_EQ(-3, iv10.getArEl(1));
		ASSERT_EQ(16, iv10.getArEl(2));
		iv11.addEl(1);
		iv10.sum(iv11);
		ASSERT_EQ(26, iv10.getArEl(0));
		ASSERT_EQ(-2, iv10.getArEl(1));
		ASSERT_EQ(17, iv10.getArEl(2));
		ASSERT_EQ( 1, iv10.getArEl(3));
	}

	TEST(Overload, overloadSum) {
		int els1[3] = { 24,-4, 15 };
		IntVector iv10(3, els1);
		int els2[3] = { 1, 1, 1 };
		IntVector iv11(3, els2);
		iv10+=iv11;
		ASSERT_EQ(25, iv10.getArEl(0));
		ASSERT_EQ(-3, iv10.getArEl(1));
		ASSERT_EQ(16, iv10.getArEl(2));
		iv11.addEl(1);
		iv10+=iv11;
		ASSERT_EQ(26, iv10.getArEl(0));
		ASSERT_EQ(-2, iv10.getArEl(1));
		ASSERT_EQ(17, iv10.getArEl(2));
		ASSERT_EQ(1, iv10.getArEl(3));
	}

	TEST(Overload, overloadMinus) {
		int els1[4] = { 24,-4, 15, -6 };
		IntVector iv10(4, els1);
		ASSERT_EQ(24, iv10.getArEl(0));
		ASSERT_EQ(-4, iv10.getArEl(1));
		ASSERT_EQ(15, iv10.getArEl(2));
		-iv10;
		ASSERT_EQ(-24, iv10.getArEl(0));
		ASSERT_EQ(4, iv10.getArEl(1));
		ASSERT_EQ(-15, iv10.getArEl(2));
	}

	TEST(Overload, overloadPlus) {
		int els1[3] = { 24,-4, 15 };
		IntVector iv10(3, els1);
		int els2[4] = { 1, 1, 1, 11};
		IntVector iv11(4, els2);
		IntVector iv12;
		iv12 = iv10 + iv11;
		ASSERT_EQ(25, iv12.getArEl(0));
		ASSERT_EQ(-3, iv12.getArEl(1));
		ASSERT_EQ(16, iv12.getArEl(2));
		ASSERT_EQ(11, iv12.getArEl(3));
	}

	TEST(Overload, overloadIndex) {
		IntVector iv10;
		iv10[1] = 5;
		iv10[9] = 17;
		ASSERT_EQ(5, iv10[1]);
		ASSERT_EQ(17, iv10[9]);
		iv10[1] = 10;
		ASSERT_EQ(10, iv10[1]);
	}

	TEST(Overload, overloadIndexException) {
		IntVector iv10;
		ASSERT_ANY_THROW(iv10[-1]);
		ASSERT_ANY_THROW(iv10[10]);
		ASSERT_ANY_THROW(iv10[-1]=1);
		ASSERT_ANY_THROW(iv10[14]=5);
	}

	TEST(Overload, overloadPreIncrement) {
		int els1[3] = { 24,-4, 15 };
		IntVector iv10(3, els1);
		ASSERT_EQ(24, (iv10)[0]);
		ASSERT_EQ(-4, (iv10)[1]);
		ASSERT_EQ(15, (iv10)[2]);
		ASSERT_EQ(25, (++iv10)[0]);
		ASSERT_EQ(-3, (iv10)[1]);
		ASSERT_EQ(16, (iv10)[2]);		
	}

	TEST(Overload, overloadPostIncrement) {
		int els1[3] = { 24,-4, 15 };
		IntVector iv10(3, els1);
		ASSERT_EQ(24, (iv10)[0]);
		ASSERT_EQ(-4, (iv10)[1]);
		ASSERT_EQ(15, (iv10)[2]);
		ASSERT_EQ(24, (iv10++)[0]);
		ASSERT_EQ(25, (iv10)[0]);
		ASSERT_EQ(-3, (iv10)[1]);
		ASSERT_EQ(16, (iv10)[2]);
	}
