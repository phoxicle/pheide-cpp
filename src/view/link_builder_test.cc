#include "link_builder.h"
#include "gtest/gtest.h"

using namespace pheide;

TEST(LinkBuilderTest, AllParams) {
	// GIVEN
	auto builder = view::LinkBuilder();

	// WHEN
	std::string link = builder
		.withController("bar")
		.withAction("foo")
		.withPageId(1)
		.withTabId(2)
		.build();

	// THEN
	EXPECT_EQ("?controller=bar&action=foo&page_id=1&tab_id=2&", link);
}

TEST(LinkBuilderTest, SomeParams) {
	// GIVEN
	auto builder = view::LinkBuilder();

	// WHEN
	std::string link = builder
		.withAction("foo")
		.withPageId(1)
		.build();

	// THEN
	EXPECT_EQ("?action=foo&page_id=1&", link);
}

TEST(LinkBuilderTest, EmptyParams) {
	// GIVEN
	auto builder = view::LinkBuilder();

	// WHEN
	std::string link = builder
		.build();

	// THEN
	EXPECT_EQ("?", link);
}

