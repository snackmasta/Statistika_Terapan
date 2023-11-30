#include <Arduino.h>

int ages[] = {30, 20, 40, 65, 45, 35, 55, 25, 50, 60};
int absences[] = {5, 3, 4, 11, 10, 6, 9, 9, 7, 6};
int n = sizeof(ages) / sizeof(ages[0]);

void setup() {
  Serial.begin(9600);

  // Calculate the Pearson correlation coefficient
  float sumXY = 0, sumX = 0, sumY = 0, sumXsq = 0, sumYsq = 0;
  for (int i = 0; i < n; ++i) {
    sumXY += ages[i] * absences[i];
    sumX += ages[i];
    sumY += absences[i];
    sumXsq += ages[i] * ages[i];
    sumYsq += absences[i] * absences[i];
  }

  float r_value = (n * sumXY - sumX * sumY) / sqrt((n * sumXsq - sumX * sumX) * (n * sumYsq - sumY * sumY));

  // Number of observations
  int df = n - 2;

  // Calculate the t-statistic
  float t_statistic = r_value * sqrt(df / (1 - r_value * r_value));

  // Critical value for two-tailed test from t-distribution with df=n-2 at alpha=0.05
  float critical_t = 2.262;  // approximate critical t-value for df=8 at alpha=0.05

  // Test the hypothesis
  bool reject_null_hypothesis = abs(t_statistic) > critical_t;

  Serial.print("r_value: ");
  Serial.println(r_value);
  Serial.print("t_statistic: ");
  Serial.println(t_statistic);
  Serial.print("critical_t: ");
  Serial.println(critical_t);
  Serial.print("reject_null_hypothesis: ");
  Serial.println(reject_null_hypothesis);
}

void loop() {
  // Nothing to do here
}