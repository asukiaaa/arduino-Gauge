#include <Gauge_asukiaaa.hpp>

Gauge_asukiaaa::Point arrPoint[] = {
    {-2, -2},
    {0, -1},
    {2, 1},
    {3, 3},
};
size_t lenPoint = sizeof(arrPoint) / sizeof(Gauge_asukiaaa::Point);
Gauge_asukiaaa::Core gauge(arrPoint, lenPoint);

void setup() { Serial.begin(115200); }

void loop() {
  for (int i = -10; i < 10; ++i) {
    Serial.println(String(i) + " -> " + String(gauge.convert(i)));
  }
  delay(5000);
}
