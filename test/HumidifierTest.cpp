/*
  MIT License

  Copyright (c) 2020 LG Electronics, Inc.

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <fff/fff.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "mocks/atomizer_spy.h"
#include "mocks/FakeHumiditySensor.hpp"
#include "humidifier/Humidifier.hpp"

using ::testing::Return;


class HumidifierTest : public ::testing::Test {
 public:
  void SetUp() override {
    RESET_FAKE(Atomizer_Set);
    humidifier = std::make_shared<Humidifier>(sensor);
  }

  FakeHumiditySensor sensor;
  std::shared_ptr<Humidifier> humidifier;
};

TEST_F(HumidifierTest, testNothingHappensWhenInitialized) {
  EXPECT_CALL(sensor, getHumidityLevel()).Times(0);  // NOLINT
  EXPECT_EQ(0, Atomizer_Set_fake.call_count);
}

TEST_F(HumidifierTest, testNothingChangesWhenHumidityLevelAsDesired) {
  EXPECT_CALL(sensor, getHumidityLevel()).WillOnce(Return(50));  // NOLINT
  humidifier->setPreferredHumidity(50);
  humidifier->onCalled();
  EXPECT_EQ(0, Atomizer_Set_fake.arg0_val);
}

TEST_F(HumidifierTest, testIncreaseHumidityLevelWhenCurrentLowerThanDesired) {
  EXPECT_CALL(sensor, getHumidityLevel()).WillOnce(Return(30));  // NOLINT
  humidifier->setPreferredHumidity(50);
  humidifier->onCalled();
  EXPECT_EQ(20, Atomizer_Set_fake.arg0_val);
}

TEST_F(HumidifierTest, testDecreaseHumidityLevelWhenCurrentLargerThanDesired) {
  EXPECT_CALL(sensor, getHumidityLevel()).WillOnce(Return(70));  // NOLINT
  humidifier->setPreferredHumidity(50);
  humidifier->onCalled();
  EXPECT_EQ(-20, Atomizer_Set_fake.arg0_val);
}
