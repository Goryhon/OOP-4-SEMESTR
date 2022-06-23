#include "gtest/gtest.h"
#include "authorizer.h"
#include <fstream>

TEST(AUTH_TESTS, REGISTER) {
    std::string filename = "test_users_1.txt";
    std::ofstream a = std::ofstream(filename);  // Создаём файл
    a << "Login,Password\n";
    a.close();
    auto auth = createBasicAuthorizer(filename);

    // Регистрируем пользователей
    EXPECT_TRUE(auth.register_user("abobus", "1234."));
    EXPECT_TRUE(auth.register_user("dedus", "777eee"));
    EXPECT_TRUE(auth.register_user("123pristup", "1246268910"));

    // Попытки зарегистрировать уже зарегистрированные имена
    EXPECT_FALSE(auth.register_user("abobus", "1234."));
    EXPECT_FALSE(auth.register_user("abobus", ";ljsakjsda;"));
    EXPECT_FALSE(auth.register_user("dedus", "777eee"));
    EXPECT_FALSE(auth.register_user("dedus", "орфолддиолфд"));
    EXPECT_FALSE(auth.register_user("123pristup", "1246268910"));
    EXPECT_FALSE(auth.register_user("123pristup", "42jk4lh32n1"));

    // Проверяем, не изменяется ли пароль при повторных попытках регистрации
    EXPECT_FALSE(auth.register_user("abobus", "123456."));
    EXPECT_FALSE(auth.log_in_user("abobus", "123456."));
}

TEST(AUTH_TESTS, LOGIN) {
    std::string filename = "test_users_2.txt";
    std::ofstream a = std::ofstream(filename);
    a << "Login,Password\n";
    a.close();
    auto auth = createBasicAuthorizer(filename);

    auth.register_user("abobus", "1234.");
    auth.register_user("dedus", "777eee");
    auth.register_user("123pristup", "1246268910");

    EXPECT_TRUE(auth.log_in_user("abobus", "1234."));
    EXPECT_TRUE(auth.log_in_user("dedus", "777eee"));
    EXPECT_TRUE(auth.log_in_user("123pristup", "1246268910"));

    EXPECT_FALSE(auth.log_in_user("abobus", "14jh51lj4ljl"));
    EXPECT_FALSE(auth.log_in_user("dedus", "00000000000000000"));
    EXPECT_FALSE(auth.log_in_user("123pristup", "12312321312"));
    EXPECT_FALSE(auth.log_in_user("who is this", "777eee"));
}