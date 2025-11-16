#include  "../includes/include.h"

int calculate_distance(int px, int py, int dx, int dy)
{
    int diff_x = dx - px;
    int diff_y = dy - py;
    double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
    return (int)distance;
}

unsigned int rgb_merge(int r, int g, int b)
{
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;
    return ((unsigned int)r << 16) | ((unsigned int)g << 8) | (unsigned int)b;
}
