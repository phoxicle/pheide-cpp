#include "link_builder.h"
#include "gtest/gtest.h"

TEST(LinkBuilderTest, AllParams) {
	// GIVEN
	auto builder = pheide::view::LinkBuilder();

	// WHEN
	std::string link = builder
		.withAction("foo")
		.withPageId(1)
		.withTabId(2)
		.build();

	// THEN
	EXPECT_EQ("?action=foo&page_id=1&tab_id=2", link);
}

TEST(LinkBuilderTest, NoTabId) {
	// GIVEN
	auto builder = pheide::view::LinkBuilder();

	// WHEN
	std::string link = builder
		.withAction("foo")
		.withPageId(1)
		.build();

	// THEN
	EXPECT_EQ("?action=foo&page_id=1", link);
}

TEST(LinkBuilderTest, EmptyParams) {
	// GIVEN
	auto builder = pheide::view::LinkBuilder();

	// WHEN
	std::string link = builder
		.build();

	// THEN
	EXPECT_EQ("?", link);
}

