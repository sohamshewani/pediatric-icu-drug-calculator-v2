#ifndef DOSAGE_CALCULATOR_H
#define DOSAGE_CALCULATOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the correct dosage
bool calculate_dosage(double patient_weight, int age, double* dosage);

// Function to validate if a dosage is within safe limits
bool validate_dosage(double dosage, double max_dosage);

#endif // DOSAGE_CALCULATOR_H