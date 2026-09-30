#include "dosage_calculator.h"
#include <math.h>

bool calculate_dosage(double patient_weight, int age, double* dosage) {
    if (patient_weight <= 0 || age <= 0) {
        return false;
    }

    // Example calculation: simple linear interpolation
    *dosage = (10 * patient_weight) / (age + 10);
    return true;
}

bool validate_dosage(double dosage, double max_dosage) {
    if (dosage < 0 || dosage > max_dosage) {
        return false;
    }
    return true;
}