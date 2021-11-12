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

#ifndef HUMIDIFIER_HPP_
#define HUMIDIFIER_HPP_

#include "common/EventListener.hpp"
#include "sensors/HumiditySensor.hpp"


class Humidifier : public EventListener {
 public:
  explicit Humidifier(const HumiditySensor& sensor);
  virtual ~Humidifier();

  void setPreferredHumidity(int level);

  void onCalled() override;

 private:
  const HumiditySensor& mSensor;
  int mPreferredLevel;
};

#endif  // HUMIDIFIER_HPP_
