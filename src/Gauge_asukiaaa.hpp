#pragma once

#include <Arduino.h>

// #define GAUGE_ASUKIAAA_DEBUG_SERIAL Serial

namespace Gauge_asukiaaa {

struct Point {
  Point(float from, float to) : from(from), to(to) {}
  const float from;
  const float to;
};

class Core {
 public:
  Core(Point* arrPoint, size_t lenPoint) {
    // TODO order by from value
    this->arrPoint = arrPoint;
    this->lenPoint = lenPoint;
  }

  float convert(float vFrom) {
    size_t indexUpper = 0;
    for (; indexUpper < lenPoint; ++indexUpper) {
      auto point = arrPoint[indexUpper];
      if (point.from > vFrom) {
        break;
      }
    }
    if (indexUpper == 0) {
      indexUpper = 1;
    } else if (indexUpper >= lenPoint) {
      indexUpper = lenPoint - 1;
    }
#ifdef GAUGE_ASUKIAAA_DEBUG_SERIAL
    GAUGE_ASUKIAAA_DEBUG_SERIAL.println("lenPoint " + String(lenPoint) +
                                        " indexUpper " + String(indexUpper));
#endif
    auto upper = arrPoint[indexUpper];
    auto lower = arrPoint[indexUpper - 1];
    if (upper.from == lower.from) return lower.from;  // invalid point input
    auto a = (upper.to - lower.to) / (upper.from - lower.from);
    auto b = lower.to - lower.from * (upper.to - lower.to) / (upper.from - lower.from);
    return a * vFrom + b;
  }

 private:
  Point* arrPoint;
  size_t lenPoint;
};

}  // namespace Gauge_asukiaaa
