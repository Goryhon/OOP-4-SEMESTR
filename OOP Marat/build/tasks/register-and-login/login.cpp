#include "authorizer.h"
#include <string>

int main() {
    std::string filename = "users.txt";
    auto auth = createBasicAuthorizer(filename);
    auth.log_in_user();
}


