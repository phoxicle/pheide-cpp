#include "query_builder.h"
#include "gtest/gtest.h"

TEST(QueryBuilderTest, AllParams) {
	// GIVEN
	auto builder = pheide::repository::QueryBuilder();

	// WHEN
	std::string q = builder
		.withFields({"field1","field2"})
		.withTable("table")
		.withWhere({ {"k1", "v1"}, {"k2", "v2"} })
		.withSorting({ "col1", "col2" })
		.withLimit(2)
		.build();

	// THEN
	EXPECT_EQ("SELECT field1,field2 FROM table WHERE k1=v1 AND k2=v2 ORDER BY col1,col2 LIMIT 2", q);
}

