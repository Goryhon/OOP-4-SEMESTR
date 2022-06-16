#include "gtest/gtest.h"
#include "stack.h"

TEST(STACK_TESTS, EMPTY_STACK) {
    stack<int> st;
    EXPECT_ANY_THROW(st.pop());
}

TEST(STACK_TESTS, PUSH_POP) {
    stack<int> st;
    st.push(552352);
    st.push(124124);
    st.push(23499450);
    st.push(421480);
    EXPECT_EQ(st.pop(), 421480);
    EXPECT_EQ(st.pop(), 23499450);

    st.push(123);
    EXPECT_EQ(st.pop(), 123);

    EXPECT_EQ(st.pop(), 124124);
    EXPECT_EQ(st.pop(), 552352);
    EXPECT_ANY_THROW(st.pop());
}

TEST(STACK_TESTS, LENGTH) {
    stack<int> st;
    EXPECT_EQ(st.length(), 0);

    st.push(4142142);
    EXPECT_EQ(st.length(), 1);

    st.push(13);
    EXPECT_EQ(st.length(), 2);

    st.pop();
    EXPECT_EQ(st.length(), 1);

    st.pop();
    EXPECT_EQ(st.length(), 0);

    EXPECT_ANY_THROW(st.pop());
}



