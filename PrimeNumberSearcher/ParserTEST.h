//
// Created by denis on 22.01.19.
//
#include "XMLparser.h"
#include "gtest/gtest.h"
#include <iostream>
#ifndef LISTATTEST_PARSERTEST_H
#define LISTATTEST_PARSERTEST_H
#endif //LISTATTEST_PARSERTEST_H

using namespace testing;

class XMLtesting : public Test{
public: XMLparser xml;
};

TEST_F(XMLtesting, getFileTEST){
    EXPECT_THROW(xml.getFile("../xmldir/TESTinput.xml"),std::logic_error);
}

TEST_F(XMLtesting, getIntervalsTEST){
    xml.getFile("../xmldir/TESTinput.xml");

    std::vector<std::pair<unsigned long long,unsigned long long>> expected = {{0,0},{0,0},{0,0}};

    ASSERT_EQ(xml.getIntervals(),expected);
}