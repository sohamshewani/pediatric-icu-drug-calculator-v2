#include "user_interface.h"
#include "dosage_calculator.h"
#include "interaction_validator.h"

void user_interface(void) {
    char drug1[20], drug2[20];
    double patient_weight, dosage, max_dosage = 1000.0;
    int age;

    printf("Welcome to the Pediatric ICU Drug Calculator\n");

    printf("Enter patient's weight (kg): ");
    if (scanf("%lf", &patient_weight) != 1) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter patient's age (years): ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter drug 1: ");
    if (fgets(drug1, sizeof(drug1), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    drug1[strcspn(drug1, "\n")] = '\0';

    printf("Enter drug 2: ");
    if (fgets(drug2, sizeof(drug2), stdin) == NULL) {
        printf("Input error.\n");
        return;
    }
    drug2[strcspn(drug2, "\n")] = '\0';

    printf("Calculating dosage...\n");
    if (calculate_dosage(patient_weight, age, &dosage) && validate_interactions(drug1, drug2) && validate_dosage(dosage, max_dosage)) {
        printf("Recommended dosage: %lf mg\n", dosage);
    } else {
        printf("Dosage calculation failed.\n");
    }
}
