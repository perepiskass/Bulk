#include <gtest/gtest.h>
#include "version_lib.h"
#include "bulk.h"




// Тест кейсы на проверку версий
TEST(version_test_case, version_test_patch)
{
    ASSERT_GE(version_patch(), 1);
}
TEST(version_test_case, version_test_minor)
{
    EXPECT_EQ(version_minor(), 1);
}
TEST(version_test_case, version_test_major)
{
    EXPECT_EQ(version_major(), 1);
}


// Тест кейсы на проверку класса Bulk

TEST(bulk_test_case, getQuantity_test)
{
    Bulk bulk(3);

    bulk.setData("one");
    bulk.setData("two");

    EXPECT_EQ(bulk.getQuantity(),2);
}

TEST(bulk_test_case, clear_data_test)
{
    Bulk bulk(3);

    bulk.setData("one");
    bulk.setData("two");
    bulk.setData("three");

    EXPECT_EQ(bulk.getQuantity(),0);

}


TEST(bulk_test_case, delimiter_clear_test)
{
    Bulk bulk(3);

    bulk.setData("one");
    bulk.setData("two");
    std::string delimiter{"{"};
    bulk.setData(std::move(delimiter));

    EXPECT_EQ(bulk.getQuantity(),0);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}