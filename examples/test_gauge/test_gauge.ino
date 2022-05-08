#include <unity.h>

#include <Gauge_asukiaaa.hpp>

Gauge_asukiaaa::Point arrPoint[] = {
    {-2, -2},
    {0, -1},
    {2, 1},
    {3, 3},
};
size_t lenPoint = sizeof(arrPoint) / sizeof(Gauge_asukiaaa::Point);
Gauge_asukiaaa::Core gauge(arrPoint, lenPoint);

Gauge_asukiaaa::Point arrTest[] = {
    {-4, -3},
    {-1, -1.5},
    {2.5, 2},
    {4, 5},
};
size_t lenTest = sizeof(arrTest) / sizeof(Gauge_asukiaaa::Point);

void test_gauge() {
  for (size_t i = 0; i < lenTest; ++i) {
    auto test = arrTest[i];
    auto result = gauge.convert(test.from);
    TEST_ASSERT_EQUAL(test.to, result);
  }
}

void setup() {
  delay(2000);  // for board that does not support software reset
  UNITY_BEGIN();
}

void loop() {
  static int testCount = 0;
  RUN_TEST(test_gauge);
  if (++testCount >= 3) {
    UNITY_END();
  }
}
