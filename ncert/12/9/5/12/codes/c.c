#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate dy/dx for the given differential equation
float dy_dx(float x, float y) {
    float numerator = -(x * y + y * y);
    float denominator = x * x;

    // Avoid division by zero or near-zero values in the denominator
    if (fabs(denominator) < 1e-6) {
        return 0.0;
    }
    return numerator / denominator;
}

// Function to calculate points using Euler's method and return them through arrays
void points(float x_0, float y_0, float x_end, float h, float *x_points, float *y_points, int steps) {
    float x_n = x_0;
    float y_n = y_0;

    for (int i = 0; i < steps; i++) {
        x_points[i] = x_n;
        y_points[i] = y_n;

        float x_n1 = x_n + h;
        float y_n1 = y_n + h * dy_dx(x_n, y_n);

        x_n = x_n1;
        y_n = y_n1;
    }
}

// Main function
int main() {
    float x_0 = 1.0; // Initial condition for x
    float y_0 = 1.0; // Initial condition for y
    float x_end = 3.0; // Final value of x
    float step_size = 0.004; // Step size for Euler's method
    int steps = (int)((x_end - x_0) / step_size) + 1;

    // Allocate memory for arrays to store points
    float *x_points = (float *)malloc(steps * sizeof(float));
    float *y_points = (float *)malloc(steps * sizeof(float));

    if (x_points == NULL || y_points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Call the points function
    points(x_0, y_0, x_end, step_size, x_points, y_points, steps);

    // Print the calculated points
    printf("x\t\ty\n");
    for (int i = 0; i < steps; i++) {
        printf("%f\t%f\n", x_points[i], y_points[i]);
    }

    // Free allocated memory
    free(x_points);
    free(y_points);

    return 0;
}

