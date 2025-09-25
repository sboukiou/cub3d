#include  "../includes/include.h"

int calculate_distance(int px, int py, int dx, int dy)
{
    int diff_x = dx - px;
    int diff_y = dy - py;
    double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
    return (int)distance;
}

