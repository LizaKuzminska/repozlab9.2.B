#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.2.B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace YourProjectNamespace {
    TEST_CLASS(StudentTests) {
public:
    TEST_METHOD(TestCreateFunction)
    {
        const int N = 2;
        Student* p = new Student[N];
        std::stringstream input;
        input << " Кузьмінська\n1\n0\n5\n4\n3\n";
        std::streambuf* originalCin = std::cin.rdbuf();
        std::cin.rdbuf(input.rdbuf());
        Create(p, N);
        std::cin.rdbuf(originalCin);
        Assert::AreEqual(std::string("Кузьмінська"), p[0].prizv);
        Assert::AreEqual(5, p[0].physics);
        Assert::AreEqual(4, p[0].math);
        Assert::AreEqual(3, p[0].program);
        delete[] p;
    }
    };
}
