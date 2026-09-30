#include "interaction_validator.h"

bool validate_interactions(const char* drug1, const char* drug2) {
    // Example interaction validation logic
    if (strcmp(drug1, "drugA") == 0 && strcmp(drug2, "drugB") == 0) {
        printf("WARNING: Drug A and Drug B can cause adverse reactions.");
        return false;
    }
    return true;
}